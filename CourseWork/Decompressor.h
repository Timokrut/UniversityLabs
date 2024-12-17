#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <string>
#include <unordered_map>

class Decompressor {
public:
    void loadDictionary(const std::string &fileName);
    std::string decode(const std::string &encodedText);

private:
    std::unordered_map<std::string, std::string> dictionary;
    std::unordered_map<std::string, std::string> reverseDictionary;
};

#endif // DECOMPRESSOR_H
