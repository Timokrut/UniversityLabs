#include <iostream>
#include <cstring>

// Создайте класс String с операциями +, +=, =, ==, !=, >, <, >=, <=.
class String
{
private:
    char* data;

public:
    String(const char* str)
    {
        data = new char [strlen(str) + 1];
        strcpy(data, str);
    }

    String (const String& other)
    {
        data = new char[strlen(other.data) + 1];
        strcpy(data, other.data);
    }
    ~String()
    {
        delete[] data;
    }

    String& operator=(const String& other)
    {
        if (this != &other)
        {
            delete[] data;
            data = new char[strlen(other.data) + 1];
            strcpy(data, other.data);
        }
        return *this;
    }

    String operator+(const String& other) const
    {
        char* result = new char[strlen(data) + strlen(other.data) + 1];
        strcpy(result, data);
        strcat(result, other.data);
        return String(result);
    }

    bool operator==(const String& other) const
    {
        return strcmp(data, other.data) == 0;
    }

    bool operator!=(const String& other) const
    {
        return !(*this == other.data);
    }

    bool operator>(const String& other) const
    {
        return strcmp(data, other.data) > 0;
    }

    bool operator<(const String& other) const
    {
        return !(*this < other.data);
    }

    bool operator>=(const String& other) const
    {
        return strcmp(data, other.data) >= 0;
    }

    bool operator<=(const String& other) const
    {
        return strcmp(data, other.data) <= 0;
    }

    void print() const
    {
        int i = 0;
        while (data[i] != '\0')
        {
            std::cout<<data[i];
            i++;
        }
        std::cout << '\n';
    }


};
int main()
{
    char first[256];
    char second[256];


    std::cout<< "Enter first string: ";  std::cin >> first;
    std::cout<< "Enter first string: ";  std::cin >> second;
    
    String s1 = first;
    String s2 = second;

    String s3 = s1 + s2;
    s3.print();

    std::cout << (s1 == s2) << std::endl;
}