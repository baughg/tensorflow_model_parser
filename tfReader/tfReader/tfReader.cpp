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
bool LoadData(const std::string &filename);

int main()
{      
    std::ofstream index_dump("log_index.txt");
    tensorflow::BundleReader reader(Env::Default(), "model.ckpt-380000");
    BundleEntryProto entry;
    reader.Seek(kHeaderEntryKey);

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
    return 0;

    std::string model_file = "model.ckpt-380000.meta";
    std::string data_file = "model.ckpt-380000.index";
    Load(model_file);
    //LoadData(data_file);
}

bool LoadData(const std::string &filename)
{
    tensorflow::BundleHeaderProto network;

    std::fstream input(filename.c_str(), std::ios::in | std::ios::binary);

    if (!network.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse tf data model." << std::endl;
        return false;
    }

    return true;
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
    const google::protobuf::Map < std::string,SignatureDef> &signature_def = network.signature_def();

    for (auto signature = signature_def.begin(); signature != signature_def.end(); signature++)
    {
        std::string sig_name = signature->first.c_str();
        printf("%s\n", sig_name.c_str());
    }

    for(auto collection = collection_def.begin(); collection != collection_def.end(); collection++)
        printf("%s\n", collection->first.c_str());

    const int nodes = graph_def.node_size();
    std::ofstream log_file("log.txt");

    for (int n = 0; n < nodes; ++n)
    {
        const tensorflow::NodeDef &node = graph_def.node(n);
        //printf("%d. %s op: %s\n", n, node.name().c_str(), node.op().c_str());
        log_file << n << " " << node.name() << " op: " << node.op() << " ";

        int inputs = node.input_size();

        for (int i = 0; i < inputs; ++i)
        {
            const std::string &input_name = node.input(i);
            log_file << "{" << input_name << "} ";
        }

        log_file << std::endl;
    }
    input.close();
    log_file.close();
    return true;
}