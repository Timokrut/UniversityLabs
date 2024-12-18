/**
 * @file Compressor.h
 * @brief Header file for the Compressor class, responsible for compressing files using the Shannon-Fano algorithm.
 */

#ifndef COMPRESSOR_H
#define COMPRESSOR_H

#include <string>
#include <unordered_map>
#include <vector>
#include "Symbol.h"

/**
 * @class Compressor
 * @brief Implements the Shannon-Fano compression algorithm.
 * 
 * The Compressor class provides functionality for analyzing text, generating codes
 * for characters based on frequency, and encoding text using the Shannon-Fano algorithm.
 */
class Compressor {
public:
    /**
     * @brief Analyzes the given text to determine character frequencies and generate codes.
     * 
     * This function processes the input text to compute the frequency of each character
     * and constructs codes for the characters based on their frequencies.
     * 
     * @param text The text to analyze.
     */
    void analyzeText(const std::string &text);
    
    /**
     * @brief Encodes the given text using the generated character codes.
     * 
     * This function encodes the input text by replacing each character with its
     * corresponding code from the generated dictionary.
     * 
     * @param text The text to encode.
     * @return The encoded text.
     */
    std::string encode(const std::string &text);
    
    /**
     * @brief Saves the generated dictionary to a file.
     * 
     * This function saves the character-to-code mappings to a file, so they can
     * be used for decompression later.
     * 
     * @param fileName The name of the file to save the dictionary.
     */
    void saveDictionary(const std::string &fileName);

private:
    std::vector<Symbol> symbols; /**< Stores the symbols (characters) and their frequencies. */
    std::unordered_map<std::string, std::string> dictionary; /**< Stores the character-to-code mappings. */

    /**
     * @brief Recursively builds the character codes based on frequencies.
     * 
     * This function is used internally to build the codes by recursively splitting
     * the set of symbols into two subsets based on frequency.
     * 
     * @param start The starting index of the current set of symbols.
     * @param end The ending index of the current set of symbols.
     */
    void buildCodes(int start, int end);
 
    /**
     * @brief Builds the dictionary of character codes.
     * 
     * This function generates the dictionary by associating each symbol with its code.
     */
    void buildDictionaries();
    
    /**
     * @brief Compares two symbols by frequency for sorting.
     * 
     * This function is used to sort symbols in decreasing order of frequency.
     * 
     * @param a The first symbol to compare.
     * @param b The second symbol to compare.
     * @return true if the frequency of symbol a is greater than that of symbol b.
     */
    static bool compareFrequency(const Symbol &a, const Symbol &b);
};

#endif // COMPRESSOR_H