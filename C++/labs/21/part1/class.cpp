#include "header.h"

Integer::Integer(int v) : value (v) {};
    
int Integer::compareTo(const Comparable& other) const  
{
    const Integer& otherInteger = (const Integer&)other;
    return this->value - otherInteger.value;
}


Person::Person(std::string name, int age) : name(name), age(age) {}

int Person::compareTo(const Comparable& other) const  
{
    const Person &otherPerson = (const Person&)other;
    return this->age - otherPerson.age;
}


int Quicksort::partition(std::vector<Comparable*>& arr, int low, int high)
{
    Comparable* pivot = arr[high];
    int i = low - 1;

    for (int j = low; j < high; j++)
        if (arr[j]->compareTo(*pivot) < 0)
        {
            i++;
            std::swap(arr[i], arr[j]);
        }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}

void Quicksort::quicksort(std::vector<Comparable*>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}
