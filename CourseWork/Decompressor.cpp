#include "Decompressor.h"
#include <fstream>

void Decompressor::loadDictionary(const std::string &fileName) {
    std::ifstream file(fileName);
    if (!file) return;

    dictionary.clear();
    std::string character;
    std::string code;
    while (file >> character >> code) {
        dictionary[character] = code;
    }
    file.close();
}

std::string Decompressor::decode(const std::string &encodedText) {
    std::string decodedText;
    std::string buffer;

    for (const auto &pair : dictionary) {
        reverseDictionary[pair.second] = pair.first;
    }

    for (char bit : encodedText) {
        buffer += bit;
        if (reverseDictionary.count(buffer)) {
            std::string decodedChar = reverseDictionary.at(buffer);
            if (decodedChar == "\\x20") {
                decodedText += ' ';
            } else if (decodedChar == "\\n") {
                decodedText += '\n';
            } else {
                decodedText += decodedChar[0];
            }
            buffer.clear();
        }
    }
    return decodedText;
}