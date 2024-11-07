// Реализовать быструю сортировку в ООП стиле 
// (наследники класса Сomparable с виртуальной функцией). 
// В main должны быть отсортированы массив Integer 
// (самодельный класса) и массив классов Person (имя, возраст).

// quicksort (array, leftindex, rightindex) - делим массив на две части, и рекурсивно сортируем каждую из них
// алгоритм стремиться расположить элементы меньше опорного - слева, больше опорного справа
// pivot - элемент, вокруг которого выполняется деление массива (обычно выбирают последний) 


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

    Integer(int v) : value (v) {}
    
    int compareTo(const Comparable& other) const override 
    {
        const Integer& otherInteger = (const Integer&)other;
        return this->value - otherInteger.value;
    }
};


class Person : public Comparable {
    public:
        std::string name;
        int age;
    
    Person(std::string name, int age) : name(name), age(age) {}

    int compareTo(const Comparable& other) const override 
    {
        const Person &otherPerson = (const Person&)other;
        return this->age - otherPerson.age;
    }
};

int partition(std::vector<Comparable*>& arr, int low, int high)
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

void quicksort(std::vector<Comparable*>& arr, int low, int high)
{
    if (low < high)
    {
        int pivotIndex = partition(arr, low, high);
        quicksort(arr, low, pivotIndex - 1);
        quicksort(arr, pivotIndex + 1, high);
    }
}

int main()
{
    std::vector<Comparable*> integers;
    integers.push_back(new Integer(3));
    integers.push_back(new Integer(1));
    integers.push_back(new Integer(4));
    integers.push_back(new Integer(2));

    quicksort(integers, 0, integers.size() - 1);
    
    std::cout << "Sorted integers" << std::endl;
    for(int i = 0; i < integers.size(); i++)
    {
        Integer* integer = (Integer*)integers[i];
        std::cout << integer->value << std::endl;
    }

    std::vector<Comparable*> persons;
    persons.push_back(new Person("Bob", 31));
    persons.push_back(new Person("Jill", 18));
    persons.push_back(new Person("Josh", 27));
    persons.push_back(new Person("Donald", 70));

    quicksort(persons, 0, persons.size() - 1);

    std::cout << "Sorted persons" << std::endl;
    for(int i = 0; i < persons.size(); i++)
    {
        Person* person = (Person*)persons[i];
        std::cout << person->name << " " << person->age << std::endl;
    }

    return 0;
}

