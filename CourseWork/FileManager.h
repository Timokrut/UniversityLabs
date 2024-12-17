#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

class FileManager {
public:
    static void writeEncodedBinary(const std::string &encodedText, const std::string &fileName);
    static std::string readEncodedBinary(const std::string &fileName);
    static std::string readFile(const std::string &fileName);
    static void writeBinaryFile(const std::string &content, const std::string &fileName);
    std::string readBinaryFile(const std::string &fileName);
    void writeFile(const std::string &content, const std::string &fileName);
};

#endif // FILEMANAGER_H