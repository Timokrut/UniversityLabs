#include "ShannonFanoTree.h"
#include "FileManager.h"

class Compressor {
private:
    ShannonFanoTree tree;

public:
    void compress(const std::string& input_file, const std::string& output_file);
};