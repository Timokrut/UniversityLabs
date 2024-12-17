#include <iostream>
#include <fstream>
#include "Compressor.h"
#include "Decompressor.h"
#include "FileManager.h"

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
        compressor.analyzeText(text);
        
        std::string encodedText = compressor.encode(text);
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
