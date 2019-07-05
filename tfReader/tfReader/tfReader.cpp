// tfReader.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "tensor_bundle.pb.h"
#include "meta_graph.pb.h"
#include "saved_object_graph.pb.h"
#include "saved_model.pb.h"
#include <iostream>
#include <fstream>

using namespace tensorflow;

bool Load(const std::string &filename);

int main()
{   
    std::string model_file = "model.ckpt-380000.meta";
    Load(model_file);
}


bool Load(const std::string &filename)
{
    tensorflow::MetaGraphDef network;

    std::fstream input(filename.c_str(), std::ios::in | std::ios::binary);

    if (!network.ParseFromIstream(&input)) {
        std::cerr << "Failed to parse tf model." << std::endl;
        return false;
    }
    
    const tensorflow::MetaGraphDef_MetaInfoDef &meta_info_def = network.meta_info_def();
    const tensorflow::GraphDef &graph_def = network.graph_def();
    const google::protobuf::Map<std::string, CollectionDef> &collection_def = network.collection_def();

    for(auto collection = collection_def.begin(); collection != collection_def.end(); collection++)
        printf("%s\n", collection->first.c_str());

    const int nodes = graph_def.node_size();

    for (int n = 0; n < nodes; ++n)
    {
        const tensorflow::NodeDef &node = graph_def.node(n);
        printf("%d. %s op: %s\n", n, node.name().c_str(), node.op().c_str());
    }
    return true;
}