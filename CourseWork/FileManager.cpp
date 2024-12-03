#include "FileManager.h"
#include <fstream>
#include <stdexcept>

std::string FileManager::readFile(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file.is_open())
        throw std::runtime_error("Unable to open file for reading");

    return std::string((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
}

void FileManager::writeFile(const std::string& filename, const std::string& data) {
    std::ofstream file(filename, std::ios::binary);
    
    if (!file.is_open()) {
        throw std::runtime_error("Unable to open file for writing");
    }
    
    // Write the encoded binary data to the file
    file.write(data.data(), data.size());
    
    if (!file) {
        throw std::runtime_error("Error writing data to file");
    }
}

