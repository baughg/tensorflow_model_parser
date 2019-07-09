#pragma once 
#include <string>

namespace tensorflow
{
    namespace port
    {
        std::string Hostname() {
            return "TensorflowMachine";
        }
    }
}