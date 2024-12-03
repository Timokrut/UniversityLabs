#pragma once

#include "ShannonFanoTree.h"
#include "FileManager.h"

class Decompressor {
private:
    ShannonFanoTree tree;

public:
    void decompress(const std::string& input_file, const std::string& output_file);
};