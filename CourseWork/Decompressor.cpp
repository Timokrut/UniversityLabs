/**
 * @file Decompressor.cpp
 * @brief Implementation of the Decompressor class.
 */

#include "Decompressor.h"
#include <fstream>

/**
 * @brief Loads the dictionary from the specified file.
 * 
 * This function reads the dictionary from a file where each line contains a character
 * and its corresponding code, and stores the mappings in the dictionary.
 * 
 * @param fileName The name of the file containing the dictionary.
 */
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

/**
 * @brief Decodes the given encoded text using the loaded dictionary.
 * 
 * This function decodes a sequence of encoded bits into a string of characters
 * by searching for matching codes in the reverse dictionary.
 * Special characters such as space and newline are handled as well.
 * 
 * @param encodedText The encoded text to decode.
 * @return The decoded text.
 */
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