#include "Compressor.h"
#include <algorithm>
#include <fstream>

bool Compressor::compareFrequency(const Symbol &a, const Symbol &b) {
    return a.frequency > b.frequency;
}

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

void Compressor::buildDictionaries() {
    for (const auto &symbol : symbols) {
        dictionary[symbol.character] = symbol.code;
    }
}

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

void Compressor::saveDictionary(const std::string &fileName) {
    std::ofstream file(fileName);
    for (const auto &pair : dictionary) {
        file << pair.first << " " << pair.second << "\n";
    }
    file.close();
}