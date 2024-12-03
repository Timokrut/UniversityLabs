#pragma once

#include <string>
#include <map>
#include <vector>
#include <algorithm>
#include <iostream>
#include <sstream>
#include <unordered_map>

class ShannonFanoTree {
private:
    std::map<char, std::string> codes;
    std::map<std::string, char> reverse_codes;
    std::unordered_map<std::string, char> decoder;

    void buildTree(const std::vector<std::pair<char, int>>& frequencies, int start, int end, std::string code);

public:
    void generateCodes(const std::string& data);
    std::string encode(const std::string& data);
    std::string decode(const std::string& binary_data);
    void buildTreeFromMetadata(const std::string& metadata);

    const std::map<char, std::string>& getCodes() const;
};