// tfReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "tensor_bundle.pb.h"
#include "meta_graph.pb.h"
#include "saved_object_graph.pb.h"
#include "saved_model.pb.h"
#include "tensorflow/core/util/tensor_bundle/tensor_bundle.h"
#include <iostream>
#include <fstream>
#include <stdio.h>

using namespace tensorflow;

bool Load(const std::string &filename);
bool LoadFrozenGraph();

int main()
{
  LoadFrozenGraph();
  return 0;

  std::string model_file = "model.ckpt-380000.meta";
  std::string database_file = "model.ckpt-380000";
  std::string data_file = "model.ckpt-380000.data-00000-of-00001";
  FILE* data_file_handle = NULL;

  data_file_handle = fopen(data_file.c_str(), "rb");

  if (!data_file_handle)
    return -1;


  std::ofstream index_dump("log_index.txt");
  tensorflow::BundleReader reader(Env::Default(), database_file);
  BundleEntryProto entry;
  reader.Seek(kHeaderEntryKey);
  std::vector<uint8_t> buffer;

  for (reader.Next(); reader.Valid(); reader.Next()) {
    const StringPiece &value = reader.value();
    const StringPiece &key = reader.key();
    CHECK(entry.ParseFromArray(value.data(), value.size()));

    if (entry.slices_size() > 0)
      continue;  // Slice of some partitioned var.

    int offset = entry.offset();
    int size = entry.size();
    DataType dt = entry.dtype();
    TensorShapeProto shape = entry.shape();

    fseek(data_file_handle, offset, SEEK_SET);
    buffer.resize(size);

    fread(reinterpret_cast<void*>(&buffer[0]), 1, size, data_file_handle);
    std::string out_filename = std::string(key.data());
    std::replace(out_filename.begin(), out_filename.end(), '/', '_');

    if (strcmp("model_resnet_model_conv2d_kernel", out_filename.c_str()) == 0)
    {
      int a = 1;
      a = 0;
    }

    if (dt == DT_FLOAT)
    {
      float* data_ptr = reinterpret_cast<float*>(&buffer[0]);
      float w = data_ptr[0];
    }


    out_filename = "model\\" + out_filename;
    out_filename.append(".bin");

    FILE* dump_binary = NULL;
    dump_binary = fopen(out_filename.c_str(), "wb");

    if (dump_binary)
    {
      fwrite(reinterpret_cast<void*>(&buffer[0]), 1, size, dump_binary);
      fclose(dump_binary);
    }

    index_dump << key << " offset: " << offset << " size: " << size << " [";

    const int dims = shape.dim_size();

    for (int d = 0; d < dims; ++d)
    {
      index_dump << shape.dim(d).size();

      if (d < (dims - 1))
        index_dump << "x";
    }

    index_dump << "]" << std::endl;
  }

  std::string debug_str = reader.DebugString();

  index_dump << "\n-------------------------------------------------------\n" << std::endl;
  index_dump << debug_str << std::endl;
  index_dump.close();

  fclose(data_file_handle);
  Load(model_file);
}

void make_safe(std::string &str)
{
  std::replace(str.begin(), str.end(), '/', '_');
  std::replace(str.begin(), str.end(), '^', '_');
  std::replace(str.begin(), str.end(), ':', '_');
}

bool Load(const std::string &filename)
{
  tensorflow::MetaGraphDef network;

  std::fstream input(filename.c_str(), std::ios::in | std::ios::binary);

  if (!network.ParseFromIstream(&input)) {
    std::cerr << "Failed to parse tf model." << std::endl;
    return false;
  }

  const int assest_count = network.asset_file_def_size();

  for (int a = 0; a < assest_count; ++a)
  {
    const tensorflow::AssetFileDef &assest = network.asset_file_def(a);
  }

  const tensorflow::SavedObjectGraph &object_graph_def = network.object_graph_def();
  int saved_nodes = object_graph_def.nodes_size();
  const tensorflow::SaverDef &saver = network.saver_def();
  const tensorflow::MetaGraphDef_MetaInfoDef &meta_info_def = network.meta_info_def();
  const int tags = meta_info_def.tags_size();
  const tensorflow::GraphDef &graph_def = network.graph_def();
  const google::protobuf::Map<std::string, CollectionDef> &collection_def = network.collection_def();
  const google::protobuf::Map < std::string, SignatureDef> &signature_def = network.signature_def();

  for (auto signature = signature_def.begin(); signature != signature_def.end(); signature++)
  {
    std::string sig_name = signature->first.c_str();
    printf("%s\n", sig_name.c_str());
  }

  for (auto collection = collection_def.begin(); collection != collection_def.end(); collection++)
    printf("%s\n", collection->first.c_str());

  const int nodes = graph_def.node_size();
  std::ofstream log_file("log.txt");

  std::string graph_filename = "nngraph.dot";
  std::ofstream nnGraph(graph_filename.c_str());

  nnGraph << "digraph G{\n" << std::endl;

  nnGraph << "\tgraph[bgcolor = white,fontname=Courier,"\
    "fontsize=8.0,labeljust=l,nojustify=true]" << std::endl;

  nnGraph << "\tnode[shape = box fillcolor = cyan style = "\
    "\"filled\" fontcolor = black]" << std::endl;

  nnGraph << "\tedge[color = black]" << std::endl;
  std::string node_name;
  std::string node_label;

  for (int n = 0; n < nodes; ++n)
  {
    const tensorflow::NodeDef &node = graph_def.node(n);
    const auto attr = node.attr();
    //printf("%d. %s op: %s\n", n, node.name().c_str(), node.op().c_str());
    node_name = node.name();
    log_file << n << " " << node_name << " op: " << node.op() << " ";

    node_label = "<B>";
    node_label.append(node_name);
    node_label.append("</B><BR/>");
    make_safe(node_name);
    size_t filter_n = node_name.find("model_resnet");
    bool add_node_to_graph = filter_n == 0;

    int inputs = node.input_size();

    for (int i = 0; i < inputs; ++i)
    {
      const std::string &input_name = node.input(i);
      std::string safeinput_name = input_name;
      make_safe(safeinput_name);

      if (add_node_to_graph) {
        nnGraph
          << "\t" << node_name
          << "->"
          << safeinput_name
          << std::endl;
      }
      log_file << "{" << input_name << "} ";
    }

    if (add_node_to_graph) {
      node_label.append("\n");
      nnGraph
        << "\t" << node_name
        << " [label=<"
        << node_label.c_str()
        << ">]"
        << std::endl;
    }

    log_file << std::endl;

    for (auto at = attr.begin(); at != attr.end(); at++)
    {
      log_file << n << " attributes: " << at->first << std::endl;
    }
  }

  input.close();
  log_file.close();
  nnGraph << "}" << std::endl;
  nnGraph.close();
  return true;
}

bool LoadFrozenGraph()
{
  std::string filename = "resnet50.pb";
  tensorflow::GraphDef graph_def;

  std::fstream input(filename.c_str(), std::ios::in | std::ios::binary);

  if (!graph_def.ParseFromIstream(&input)) {
    std::cerr << "Failed to parse tf model." << std::endl;
    return false;
  }

  const int nodes = graph_def.node_size();

  std::string graph_filename = "nngraph.dot";
  std::ofstream nnGraph(graph_filename.c_str());

  nnGraph << "digraph G{\n" << std::endl;

  nnGraph << "\tgraph[bgcolor = white,fontname=Courier,"\
    "fontsize=8.0,labeljust=l,nojustify=true]" << std::endl;

  nnGraph << "\tnode[shape = box fillcolor = cyan style = "\
    "\"filled\" fontcolor = black]" << std::endl;

  nnGraph << "\tedge[color = black]" << std::endl;
  std::string node_name;
  std::string node_label;

  for (int n = 0; n < nodes; ++n)
  {
    const tensorflow::NodeDef &node = graph_def.node(n);
    const auto attr = node.attr();  
    node_name = node.name();
    
    node_label = "<B>";
    node_label.append(node_name);
    node_label.append("</B><BR/>");
    make_safe(node_name);
    size_t filter_n = node_name.find("model_resnet");
    bool add_node_to_graph = filter_n == 0;
    add_node_to_graph = true;

    int inputs = node.input_size();

    for (int i = 0; i < inputs; ++i)
    {
      const std::string &input_name = node.input(i);
      std::string safeinput_name = input_name;
      make_safe(safeinput_name);

      if (add_node_to_graph) {
        nnGraph
          << "\t" << safeinput_name
          << "->"
          << node_name
          << std::endl;
      }     
    }

    if (add_node_to_graph) {
      node_label.append("\n");
      nnGraph
        << "\t" << node_name
        << " [label=<"
        << node_label.c_str()
        << ">]"
        << std::endl;
    }
  }

  input.close();  
  nnGraph << "}" << std::endl;
  nnGraph.close();
  return true;
}