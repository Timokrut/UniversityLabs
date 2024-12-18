/**
 * @file Decompressor.h
 * @brief Header file for the Decompressor class, responsible for decompressing files compressed with the Shannon-Fano algorithm.
 */

#ifndef DECOMPRESSOR_H
#define DECOMPRESSOR_H

#include <string>
#include <unordered_map>

/**
 * @class Decompressor
 * @brief Implements the decompression logic for Shannon-Fano compressed files.
 * 
 * The Decompressor class provides functionality to load a dictionary of character codes
 * and decode an encoded string based on the Shannon-Fano algorithm.
 */
class Decompressor {
public:
    /**
     * @brief Loads the dictionary from a file.
     * 
     * This function reads the character-to-code mappings from a file and stores them
     * in the dictionary for decoding.
     * 
     * @param fileName The name of the file containing the dictionary.
     */
    void loadDictionary(const std::string &fileName);
    
    /**
     * @brief Decodes an encoded string using the loaded dictionary.
     * 
     * This function decodes the given encoded text into its original form by
     * matching the encoded bits with entries in the reverse dictionary.
     * 
     * @param encodedText The encoded text to decode.
     * @return The decoded text.
     */
    std::string decode(const std::string &encodedText);

private:
    std::unordered_map<std::string, std::string> dictionary; /**< Stores the character-to-code mappings. */
    std::unordered_map<std::string, std::string> reverseDictionary; /**< Stores the code-to-character mappings for decoding. */
};

#endif // DECOMPRESSOR_H
