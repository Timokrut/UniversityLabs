/**
 * @file main.cpp
 * @brief Entry point of the program, handling command-line arguments for compression and decompression.
 */

#include <ctime>
#include <iostream>
#include <chrono>
#include "Compressor.h"
#include "Decompressor.h"
#include "FileManager.h"

/**
 * @brief Main function to compress or decompress files based on command-line arguments.
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return Exit code of the program.
 */
int main(int argc, char* argv[]) {
    if (argc < 4) {
        std::cerr << "Usage: <encode|decode> <input_file> <output_file>" << std::endl;
        return 1;
    }

    std::string mode = argv[1];
    std::string inputFileName = argv[2];
    std::string dictionaryFileName = "dictionary.txt";
    std::string outputFileName = argv[3];

    if (mode == "encode") {
        FileManager fileManager;
        std::string text = fileManager.readFile(inputFileName);
        
        Compressor compressor;
        
        auto start = std::chrono::high_resolution_clock::now();

        compressor.analyzeText(text);
       
        std::string encodedText = compressor.encode(text);

        auto end = std::chrono::high_resolution_clock::now();

        auto duration = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count();
        std::cout << "Time taken for encode: " << duration << " ms" << std::endl;

        compressor.saveDictionary(dictionaryFileName);
        fileManager.writeBinaryFile(encodedText, outputFileName);

    } else if (mode == "decode") {
        FileManager fileManager;
        std::string encodedText = fileManager.readBinaryFile(inputFileName);

        Decompressor decompressor;
        decompressor.loadDictionary(dictionaryFileName);

        std::string decodedText = decompressor.decode(encodedText);
        fileManager.writeFile(decodedText, outputFileName);

    } else {
        std::cerr << "Unknown mode: " << mode << ". Use 'encode' or 'decode'." << std::endl;
        return 1;
    }

    return 0;
}
