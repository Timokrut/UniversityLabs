#include "Compressor.h"

void Compressor::compress(const std::string& input_file, const std::string& output_file) {
    std::string data = FileManager::readFile(input_file);
    tree.generateCodes(data);

    std::string encoded_data = tree.encode(data);

    std::string metadata;
    for (const auto& [symbol, code] : tree.getCodes()) {
        metadata += symbol + std::to_string(code.size()) + code;
    }

    FileManager::writeFile(output_file, metadata + '\n' + encoded_data);
}
