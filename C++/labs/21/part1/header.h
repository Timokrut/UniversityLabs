#include <algorithm>
#include <ostream>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

class Comparable {
    public:
        virtual int compareTo(const Comparable& other) const = 0;
        virtual ~Comparable() = default;
};

class Integer : public Comparable {
    public:
        int value;

    Integer(int v);
    
    int compareTo(const Comparable& other) const override ; 
};


class Person : public Comparable {
    public:
        std::string name;
        int age;
    
    Person(std::string name, int age);

    int compareTo(const Comparable& other) const override; 
};

class Quicksort {
    public:
        int partition(std::vector<Comparable*>& arr, int low, int high);
        void quicksort(std::vector<Comparable*>& arr, int low, int high);
};
