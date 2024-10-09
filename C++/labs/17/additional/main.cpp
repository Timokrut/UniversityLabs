#include "header.h"
#include <iostream>
#include <ostream>

// insert : DONE (add) 
// erase : DONE
// exception on empty : DONE
// bool find : DONE (contains)
// size : DONE
// clear : DONE
// operator<< - cout : DONE


int main()
{
    Set<int> i_set(1);
    i_set.add(3);
    i_set.add(2);
    i_set.add(1);

    Set<float> f_set(1);
    f_set.add(3.5);
    f_set.add(2.5);
    f_set.add(1.5);

    try {
        Set<int> n_set(0); 
    }
    catch(const std::runtime_error& e) {
        std::cout << e.what() << std::endl;
    }
    
    std::cout << i_set << std::endl;
    std::cout << f_set << std::endl;

    i_set.clear();
    std::cout << "Integer Set after clearing: " << i_set << std::endl;
    
    f_set.erase(5.0);
    std::cout << "Trying to remove 5.0 " << f_set << std::endl;
    
    f_set.erase(1.5);
    std::cout << "Trying to remove 1.5 " << f_set << std::endl;

    
    std::cout << "Multiple addition to empty array" << std::endl;
    int data[] = {1, 2, 3, 4, 5};
    i_set.addM(data, sizeof(data)/sizeof(data[0]));
    std::cout << i_set << std::endl;

    std::cout << "Multiple erasing to previous array" << std::endl;
    int data2[] = {1, 3, 5};
    i_set.removeM(data2, sizeof(data2)/sizeof(data2[0]));
    std::cout << i_set << std::endl;


    return 0;
}
