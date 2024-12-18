/**
 * @file FileManager.h
 * @brief Header file for the FileManager class, responsible for file operations.
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include <string>

/**
 * @class FileManager
 * @brief Provides utility methods for reading and writing files in text or binary format.
 */
class FileManager {
public:
    /**
     * @brief Writes encoded binary data to a file.
     * @param encodedText The binary data represented as a string of bits.
     * @param fileName The name of the file to write to.
     */
    static void writeEncodedBinary(const std::string &encodedText, const std::string &fileName);

    /**
     * @brief Reads binary data from a file and returns it as a string of bits.
     * @param fileName The name of the file to read from.
     * @return A string containing the binary data.
     */
    static std::string readEncodedBinary(const std::string &fileName);
    
    /**
     * @brief Reads the contents of a text file.
     * @param fileName The name of the file to read from.
     * @return A string containing the file's contents.
     */
    static std::string readFile(const std::string &fileName);
    
    /**
     * @brief Writes encoded binary data to a file.
     * @param content The binary data represented as a string of bits.
     * @param fileName The name of the file to write to.
     */
    static void writeBinaryFile(const std::string &content, const std::string &fileName);
    
    /**
     * @brief Reads binary data from a file and returns it as a string of bits.
     * @param fileName The name of the file to read from.
     * @return A string containing the binary data.
     */
    std::string readBinaryFile(const std::string &fileName);
    
    /**
     * @brief Writes plain text to a file.
     * @param content The text content to write.
     * @param fileName The name of the file to write to.
     */
    void writeFile(const std::string &content, const std::string &fileName);
};

#endif // FILEMANAGER_H