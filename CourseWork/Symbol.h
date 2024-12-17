#include <string>

class Symbol {
public:
    std::string character;
    int frequency;
    std::string code;

    Symbol(std::string character, int frequency);
};