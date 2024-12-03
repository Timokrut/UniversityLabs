#pragma once

#include <string>
#include <fstream>
#include <stdexcept>


class FileManager {
public:
    static std::string readFile(const std::string& filename);
    static void writeFile(const std::string& filename, const std::string& data);
};