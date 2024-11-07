// Реализовать быструю сортировку в ООП стиле 
// (наследники класса Сomparable с виртуальной функцией). 
// В main должны быть отсортированы массив Integer 
// (самодельный класса) и массив классов Person (имя, возраст).

// quicksort (array, leftindex, rightindex) - делим массив на две части, и рекурсивно сортируем каждую из них
// алгоритм стремиться расположить элементы меньше опорного - слева, больше опорного справа
// pivot - элемент, вокруг которого выполняется деление массива (обычно выбирают последний) 

#include "header.h"

int main()
{
    Quicksort q;

    std::vector<Comparable*> integers;
    integers.push_back(new Integer(3));
    integers.push_back(new Integer(1));
    integers.push_back(new Integer(4));
    integers.push_back(new Integer(2));

    q.quicksort(integers, 0, integers.size() - 1);
    
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

    q.quicksort(persons, 0, persons.size() - 1);

    std::cout << "Sorted persons" << std::endl;
    for(int i = 0; i < persons.size(); i++)
    {
        Person* person = (Person*)persons[i];
        std::cout << person->name << " " << person->age << std::endl;
    }

    return 0;
}

