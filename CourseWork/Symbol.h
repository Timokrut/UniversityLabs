/**
 * @file Symbol.h
 * @brief Header file for the Symbol class, representing a character and its frequency in the input text.
 */

#ifndef SYMBOL_H
#define SYMBOL_H

#include <string>

/**
 * @class Symbol
 * @brief Represents a single character, its frequency, and its binary code in the compression process.
 */
class Symbol {
public:
    std::string character; ///< The character represented by this symbol.
    int frequency;         ///< The frequency of the character in the input text.
    std::string code;      ///< The binary code assigned to the character during compression.

    /**
     * @brief Constructs a Symbol object.
     * @param character The character represented by this symbol.
     * @param frequency The frequency of the character in the input text.
     */
    Symbol(std::string character, int frequency);
};

#endif // SYMBOL_H