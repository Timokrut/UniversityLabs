#include <iostream>
#include <algorithm>

class IntSet 
{
private:
    static const int MAX_SIZE = 1000; 
    int elements[MAX_SIZE];           
    int size;                         

public:
    IntSet() : size(0) {}

    void add(int num) 
    {
        if (!contains(num) && size < MAX_SIZE) 
            elements[size++] = num;
    }

    void remove(int num) 
    {
        for (int i = 0; i < size; ++i) 
            if (elements[i] == num) 
            {
                for (int j = i; j < size - 1; ++j) 
                    elements[j] = elements[j + 1];
                size--;
                break;
            }
    }

    bool contains(int num) const 
    {
        for (int i = 0; i < size; ++i) 
            if (elements[i] == num) 
                return true;
        return false;
    }

    void print() const 
    {
        std::cout << "{";
        for (int i = 0; i < size; i++) 
            {
                if (i == (size - 1))
                {
                    std::cout << elements[i];
                    break;
                }

                std::cout << elements[i] << ", ";

            }
        std::cout << "}" << std::endl;
    }
    
    IntSet operator+(const IntSet& other) const 
    {
        IntSet result = *this;
        for (int i = 0; i < other.size; ++i)
            result.add(other.elements[i]);
        return result;
    }
    
    IntSet& operator+=(const IntSet& other) 
    {
        for (int i = 0; i < other.size; ++i)
            add(other.elements[i]);
        return *this;
    }
    
    IntSet operator-(const IntSet& other) const 
    {
        IntSet result;
        for (int i = 0; i < size; ++i)
            if (!other.contains(elements[i]))
                result.add(elements[i]);
        return result;
    }
    
    IntSet& operator-=(const IntSet& other) 
    {
        for (int i = 0; i < size; ++i)
            if (other.contains(elements[i]))
                remove(elements[i]);
        return *this;
    }
    
    bool operator==(const IntSet& other) const 
    {
        if (size != other.size)
            return false;
        IntSet sorted_this = *this;
        IntSet sorted_other = other;
        std::sort(sorted_this.elements, sorted_this.elements + sorted_this.size);
        std::sort(sorted_other.elements, sorted_other.elements + sorted_other.size);
        for (int i = 0; i < size; ++i)
            if (sorted_this.elements[i] != sorted_other.elements[i])
                return false;
        return true;
    }
    
    bool operator!=(const IntSet& other) const 
    {
        return !(*this == other);
    }
    
    bool operator>(const IntSet& other) const 
    {
        return size > other.size;
    }
    
    bool operator<(const IntSet& other) const 
    {
        return size < other.size;
    }
    
    bool operator>=(const IntSet& other) const 
    {
        return size >= other.size;
    }
    
    bool operator<=(const IntSet& other) const 
    {
        return size <= other.size;
    }
    
    IntSet operator*(const IntSet& other) const 
    {
        IntSet result;
        for (int i = 0; i < size; ++i)
            if (other.contains(elements[i]))
                result.add(elements[i]);
        return result;
    }
    
    IntSet operator+(int num) const 
        {
            IntSet result = *this;
            result.add(num);
            return result;
        }
    
    IntSet operator-(int num) const 
    {
        IntSet result = *this;
        result.remove(num);
        return result;
    }

        const int* getElements() const
    {
        return elements;
    }

    int getSize() const
    {
        return size;
    }

    friend std::ostream& operator<<(std::ostream& os, const IntSet& set);
    friend std::istream& operator>>(std::istream& is, IntSet& set);

};

std::ostream& operator<<(std::ostream& os, const IntSet& set)
{
    os << "{";
    for (int i = 0; i < set.size; ++i)
    {
        if (i == set.size - 1)
            os << set.elements[i];
        else
            os << set.elements[i] << ", ";
    }
    os << "}";
    return os;
}

std::istream& operator>>(std::istream& is, IntSet& set)
{
    int num;
    is >> num;
    set.add(num);
    return is;
}


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

    return 0;
}