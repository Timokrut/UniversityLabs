#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Symbol.h"

class Compressor {
public:
    void analyzeText(const std::string &text);
    std::string encode(const std::string &text);
    void saveDictionary(const std::string &fileName);

private:
    std::vector<Symbol> symbols;
    std::unordered_map<std::string, std::string> dictionary;

    void buildCodes(int start, int end);
    void buildDictionaries();
    static bool compareFrequency(const Symbol &a, const Symbol &b);
};

#endif // COMPRESSOR_H