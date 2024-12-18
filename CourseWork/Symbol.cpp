/**
 * @file Symbol.cpp
 * @brief Implementation of the Symbol class.
 */

#include "Symbol.h"

/**
 * @brief Constructs a Symbol object.
 * @param character The character represented by this symbol.
 * @param frequency The frequency of the character in the input text.
 */
Symbol::Symbol(std::string character, int frequency) : character(character), frequency(frequency) {}