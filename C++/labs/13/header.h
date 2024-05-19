#include <iostream>

class IntSet 
{
private:
    int* elements;           
    int size;                         
    int capacity;

    void resize(int newCapacity);

public:
    IntSet();
    ~IntSet();
    IntSet(const IntSet& other);
    IntSet& operator=(const IntSet& other);

    void add(int num);
    void remove(int num);
    bool contains(int num) const;
    void print() const;

    IntSet operator+(const IntSet& other) const;
    IntSet& operator+=(const IntSet& other);
    IntSet operator-(const IntSet& other) const;
    IntSet& operator-=(const IntSet& other);

    bool operator==(const IntSet& other) const;
    bool operator!=(const IntSet& other) const;
    bool operator>(const IntSet& other) const;
    bool operator<(const IntSet& other) const;
    bool operator>=(const IntSet& other) const;
    bool operator<=(const IntSet& other) const;

    IntSet operator*(const IntSet& other) const;
    IntSet operator+(int num) const;
    IntSet operator-(int num) const;

    const int* getElements() const;
    int getSize() const;

    friend std::ostream& operator<<(std::ostream& os, const IntSet& set);
    friend std::istream& operator>>(std::istream& is, IntSet& set);

    IntSet leftJoin (const IntSet& other) const;
    IntSet rightJoin (const IntSet& other) const;
    IntSet leftJoinNull (const IntSet& other) const;
    IntSet rightJoinNull (const IntSet& other) const;
};
