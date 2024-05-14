#include "header.h"
#include <iostream>

int main()
{
    IntSet set1, set2;

    IntSet set3;

    set1.add(1);
    set2.add(2);

    set3 = set1 + set2;

    std::cout << (set3) << std::endl;

    IntSet set4;
    set4.add(5);

    set3 += set4;

    std::cout << (set3) << std::endl;

    set3 -= set4;
    std::cout << (set3) << std::endl;

    std::cout << (set1 == set2) << std::endl;
    std::cout << (set1 != set2) << std::endl;
    std::cout << (set1 > set3) << std::endl;
    std::cout << (set1 < set3) << std::endl;
    std::cout << (set1 >= set3) << std::endl;
    std::cout << (set1 <= set3) << std::endl;

    std::cout << (set1 * set3) << std::endl;
    std::cout << (set3 * set1) << std::endl;

    std::cout << (set1 + 10) << std::endl;

    std::cout << (set1 - 7) << std::endl;


    IntSet set5;
    std::cout << "Enter integers to add to the set (non-integer to stop): ";
    while (std::cin >> set5) {
        std::cout << "Current set: " << set5 << std::endl;
    }


    return 0;
}