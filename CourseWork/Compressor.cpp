/**
 * @file Compressor.cpp
 * @brief Implementation of the Compressor class.
 */

#include "Compressor.h"
#include <algorithm>
#include <fstream>

/**
 * @brief Compares symbols by frequency for sorting.
 * 
 * This function is used to sort symbols in descending order of frequency.
 * 
 * @param a The first symbol.
 * @param b The second symbol.
 * @return true if the frequency of symbol a is greater than symbol b.
 */
bool Compressor::compareFrequency(const Symbol &a, const Symbol &b) {
    return a.frequency > b.frequency;
}

/**
 * @brief Recursively builds the codes for symbols based on their frequencies.
 * 
 * This function recursively divides the set of symbols into two subsets based on
 * their frequencies and assigns binary codes.
 * 
 * @param start The starting index of the current set.
 * @param end The ending index of the current set.
 */
void Compressor::buildCodes(int start, int end) {
    if (start >= end) return;

    int totalFrequency = 0;
    for (int i = start; i <= end; ++i) {
        totalFrequency += symbols[i].frequency;
    }

    int halfFrequency = 0;
    int splitIndex = start;
    for (int i = start; i <= end; ++i) {
        halfFrequency += symbols[i].frequency;
        if (halfFrequency >= totalFrequency / 2) {
            splitIndex = i;
            break;
        }
    }

    for (int i = start; i <= splitIndex; ++i) {
        symbols[i].code += "0";
    }

    for (int i = splitIndex + 1; i <= end; ++i) {
        symbols[i].code += "1";
    }

    buildCodes(start, splitIndex);
    buildCodes(splitIndex + 1, end);
}

/**
 * @brief Builds the dictionary of character codes.
 * 
 * This function generates a dictionary of characters and their corresponding binary codes.
 */
void Compressor::buildDictionaries() {
    for (const auto &symbol : symbols) {
        dictionary[symbol.character] = symbol.code;
    }
}

/**
 * @brief Analyzes the text to determine the frequency of characters and generate codes.
 * 
 * This function processes the text and generates a frequency table for each character
 * in the text. It then generates the codes based on the frequencies.
 * 
 * @param text The text to analyze.
 */
void Compressor::analyzeText(const std::string &text) {
    std::unordered_map<std::string, int> frequency;
    for (char c : text) {
        if (c == ' ') {
            frequency["\\x20"]++;
        } else if (c == '\n') {
            frequency["\\n"]++;
        } else {
            frequency[std::string(1, c)]++;
        }
    }

    for (const auto &pair : frequency) {
        symbols.emplace_back(pair.first, pair.second);
    }

    std::sort(symbols.begin(), symbols.end(), compareFrequency);
    buildCodes(0, symbols.size() - 1);
    buildDictionaries();
}

/**
 * @brief Encodes the input text using the generated dictionary.
 * 
 * This function encodes the input text by replacing each character with its corresponding
 * binary code from the generated dictionary.
 * 
 * @param text The text to encode.
 * @return The encoded text.
 */
std::string Compressor::encode(const std::string &text) {
    std::string encodedText;
    for (char c : text) {
        if (c == ' ') {
            encodedText += dictionary.at("\\x20");
        } else if (c == '\n') {
            encodedText += dictionary.at("\\n");
        } else {
            encodedText += dictionary.at(std::string(1, c));
        }
    }
    return encodedText;
}

/**
 * @brief Saves the dictionary to a file.
 * 
 * This function writes the character-to-code mappings to a file, where each line
 * contains a character and its corresponding code.
 * 
 * @param fileName The name of the file to save the dictionary.
 */
void Compressor::saveDictionary(const std::string &fileName) {
    std::ofstream file(fileName);
    for (const auto &pair : dictionary) {
        file << pair.first << " " << pair.second << "\n";
    }
    file.close();
}