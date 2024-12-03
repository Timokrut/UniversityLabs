#include "ShannonFanoTree.h"

void ShannonFanoTree::buildTree(const std::vector<std::pair<char, int>>& frequencies, int start, int end, std::string code) {
    std::cout << "buildTree called with start: " << start << ", end: " << end << ", code: " << code << std::endl;

    if (start > end) {
        std::cout << "start > end, returning" << std::endl;
        return;
    }

    if (start == end) {
        std::cout << "Base case reached for index: " << start << " with character: " << frequencies[start].first 
                  << " and code: " << code << std::endl;
        codes[frequencies[start].first] = code;
        reverse_codes[code] = frequencies[start].first;
        return;
    }

    int total_sum = 0;
    for (int i = start; i <= end; ++i)
        total_sum += frequencies[i].second;

    std::cout << "Total sum of frequencies between " << start << " and " << end << ": " << total_sum << std::endl;

    int split_index = start;
    int left_sum = 0;

    while (split_index <= end && left_sum + frequencies[split_index].second <= total_sum / 2) {
        left_sum += frequencies[split_index].second;
        split_index++;
    }

    if (split_index == start) {
        split_index++;
    }

    std::cout << "Split index found at: " << split_index << " with left sum: " << left_sum << std::endl;

    buildTree(frequencies, start, split_index - 1, code + "0");
    buildTree(frequencies, split_index, end, code + "1");
}


void ShannonFanoTree::generateCodes(const std::string& data) {
    std::cout << "Generating codes for data: " << data << std::endl;

    std::map<char, int> frequency_map;
    for (char c : data) {
        frequency_map[c]++;
    }

    std::cout << "Frequency Map: " << std::endl;
    for (const auto& pair : frequency_map) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    std::vector<std::pair<char, int>> frequencies(frequency_map.begin(), frequency_map.end());
    std::sort(frequencies.begin(), frequencies.end(), [](auto& a, auto& b) {
        return a.second > b.second;
    });

    std::cout << "Sorted Frequencies: " << std::endl;
    for (const auto& pair : frequencies) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    
    buildTree(frequencies, 0, frequencies.size() - 1, "");
}



std::string ShannonFanoTree::encode(const std::string& data) {
    std::cout << "Encoding data: " << data << std::endl;
    std::string encoded;
    for (char c : data) {
        encoded += codes[c];
        std::cout << "Encoding char " << c << " -> " << codes[c] << std::endl;
    }
    return encoded;
}

std::string ShannonFanoTree::decode(const std::string& encoded_data) {
    std::string decoded_data;
    std::string current_code;

    for (char bit : encoded_data) {
        current_code += bit; 

        if (decoder.find(current_code) != decoder.end()) {
            decoded_data += decoder.at(current_code);
            current_code.clear(); 
        }
    }

    return decoded_data;

}

const std::map<char, std::string>& ShannonFanoTree::getCodes() const { return codes; }

void ShannonFanoTree::buildTreeFromMetadata(const std::string& metadata) {
    size_t i = 0;
    while (i < metadata.size()) {
        char symbol = metadata[i++];
        int length = metadata[i++] - '0'; 
        std::string code = metadata.substr(i, length);
        decoder[code] = symbol;
        i += length;
    }
}
