#include "Compressor.h"
#include "Decompressor.h"
#include <iostream>
#include <stdexcept>

int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: <mode> <input_file> <output_file>\n";
        std::cerr << "Modes: -c (compress), -d (decompress)\n";
        return 1;
    }

    std::string mode = argv[1];
    std::string input_file = argv[2];
    std::string output_file = argv[3];

    try {
        if (mode == "-c") {
            Compressor compressor;
            compressor.compress(input_file, output_file);
        } else if (mode == "-d") {
            Decompressor decompressor;
            decompressor.decompress(input_file, output_file);
        } else {
            throw std::invalid_argument("Invalid mode. Use -c or -d.");
        }

        std::cout << "Operation completed successfully.\n";
    } catch (const std::exception& ex) {
        std::cerr << "Error: " << ex.what() << "\n";
        return 1;
    }

    return 0;
}
// g++ -std=c++17 -Wall main.cpp Compressor.cpp Decompressor.cpp FileManager.cpp ShannonFanoTree.cpp -o shannon_fano
