#include "FileManager.h"
#include <fstream>
#include <iostream>

void FileManager::writeEncodedBinary(const std::string &encodedText, const std::string &fileName) {
    std::ofstream outputFile(fileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Fault: can't open file " << fileName << std::endl;
        return;
    }

    unsigned char buffer = 0;
    int bitCount = 0;

    for (char bit : encodedText) {
        buffer = (buffer << 1) | (bit - '0');
        ++bitCount;

        if (bitCount == 8) {
            outputFile.put(buffer);
            buffer = 0;
            bitCount = 0;
        }
    }

    if (bitCount > 0) {
        buffer <<= (8 - bitCount);
        outputFile.put(buffer);
    }

    outputFile.close();
}

std::string FileManager::readEncodedBinary(const std::string &fileName) {
    std::ifstream inputFile(fileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Fault: can't open file " << fileName << std::endl;
        return "";
    }

    std::string encodedText;
    unsigned char buffer;

    while (inputFile.get(reinterpret_cast<char &>(buffer))) {
        for (int i = 7; i >= 0; --i) {
            encodedText += ((buffer >> i) & 1) ? '1' : '0';
        }
    }

    inputFile.close();
    return encodedText;
}

std::string FileManager::readFile(const std::string &fileName) {
    std::ifstream inputFile(fileName);
    if (!inputFile) {
        std::cerr << "Fault: can't open file " << fileName << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    return content;
}

void FileManager::writeBinaryFile(const std::string &content, const std::string &fileName) {
    std::ofstream outputFile(fileName, std::ios::binary);
    if (!outputFile) {
        std::cerr << "Fault: can't open file " << fileName << std::endl;
        return;
    }

    outputFile.write(content.c_str(), content.size());
    outputFile.close();
}
std::string FileManager::readBinaryFile(const std::string &fileName) {
    std::ifstream inputFile(fileName, std::ios::binary);
    if (!inputFile) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return "";
    }

    std::string content((std::istreambuf_iterator<char>(inputFile)), std::istreambuf_iterator<char>());
    inputFile.close();
    return content;
}

void FileManager::writeFile(const std::string &content, const std::string &fileName) {
    std::ofstream outputFile(fileName);
    if (!outputFile) {
        std::cerr << "Error: Unable to open file " << fileName << std::endl;
        return;
    }

    outputFile << content;
    outputFile.close();
}
