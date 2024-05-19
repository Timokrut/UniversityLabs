#include "header.h"
#include <iostream>

int main()
{
    IntSet set1, set2;

    IntSet set3;

    set1.add(1);
    set2.add(2);

    std::cout << "Set 1 = " << set1 << std::endl;
    std::cout << "Set 2 = " << set2 << std::endl;

    set3 = set1 + set2;

    std::cout << "Set 1 + Set 2 = Set 3 = " << (set3) << std::endl;

    IntSet set4;
    set4.add(5);

    std::cout << "Set 4 = " << set4 << std::endl;

    set3 += set4;

    std::cout << "Set 3 += Set 4 = " << set3 << std::endl;

    std::cout << (set3) << std::endl;

    set3 -= set4;

    std::cout << "Set 3 -= Set 4 = " << set3 << std::endl;
    std::cout << (set3) << std::endl;


    // std::cout << (set1 == set2) << std::endl;
    std::cout << "Set 1 == Set 2? - " << ((set1 == set2) ? "True" : "False" )<< std::endl;
    // std::cout << (set1 != set2) << std::endl;
    std::cout << "Set 1 != Set 2? - " << ((set1 != set2) ? "True" : "False" )<< std::endl;
    // std::cout << (set1 > set3) << std::endl;
    std::cout << "Set 1 > Set 3? - " << ((set1 > set3) ? "True" : "False" )<< std::endl;
    // std::cout << (set1 < set3) << std::endl;
    std::cout << "Set 1 < Set 3? - " << ((set1 < set3) ? "True" : "False" )<< std::endl;
    // std::cout << (set1 >= set3) << std::endl;
    std::cout << "Set 1 >= Set 3? - " << ((set1 >= set3) ? "True" : "False" )<< std::endl;
    // std::cout << (set1 <= set3) << std::endl;
    std::cout << "Set 1 <= Set 3? - " << ((set1 <= set3) ? "True" : "False" )<< std::endl;


    // std::cout << (set1 * set3) << std::endl;
    std::cout << "Set 1 * Set 3 = " << ((set1 * set3))<< std::endl;
    // std::cout << (set3 * set1) << std::endl;
    std::cout << "Set 3 * Set 1 = " << ((set3 * set1))<< std::endl;

    set1 = set1 + 10;
    // std::cout << (set1) << std::endl;
    std::cout << "Set 1 + 10 = " << (set1)<< std::endl;
    


    set1 = set1 - 7;
    // std::cout << (set1) << std::endl;
    std::cout << "Set 1 - 7 = " << (set1)<< std::endl;

    // IntSet set5;
    // std::cout << "Enter integers to add to the set (non-integer to stop): ";
    // while (std::cin >> set5) {
    //     std::cout << "Current set: " << set5 << std::endl;
    // }

    IntSet set6;
    IntSet set7;

    set6.add(1);
    set6.add(2);
    set6.add(3);

    set7.add(2);
    set7.add(3);
    set7.add(4);

    std::cout << "Set 6 = " << set6 <<std::endl;
    std::cout << "Set 7 = " << set7 <<std::endl;

    std::cout<< "Left Join: " << set6.leftJoin(set7) << std::endl;
    std::cout<< "Right Join " << set6.rightJoin(set7) << std::endl;
    std::cout<< "Left Join Null " << set6.leftJoinNull(set7) << std::endl; 
    std::cout<< "Right Join Null " << set6.rightJoinNull(set7) << std::endl;

    return 0;
}