#include "Decompressor.h"

void Decompressor::decompress(const std::string& input_file, const std::string& output_file) {
    std::string file_content = FileManager::readFile(input_file);
    size_t separator_pos = file_content.find('\n');

    std::string metadata = file_content.substr(0, separator_pos);
    std::cout << "Read metadata: " << metadata << std::endl; 
    
    std::string encoded_data = file_content.substr(separator_pos + 1);
    std::cout << "Read encoded_data: " << encoded_data << std::endl; 

    tree.buildTreeFromMetadata(metadata);

    std::string decoded_data = tree.decode(encoded_data);

    FileManager::writeFile(output_file, decoded_data);
}
