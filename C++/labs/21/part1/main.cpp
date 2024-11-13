// Реализовать быструю сортировку в ООП стиле 
// (наследники класса Сomparable с виртуальной функцией). 
// В main должны быть отсортированы массив Integer 
// (самодельный класса) и массив классов Person (имя, возраст).

#include "header.h"
#include <fstream>
#include <iostream>
#include <ostream>
#include <sstream>
#include <string>

int main()
{
    Quicksort q;

    std::ifstream inputFile("integers.txt");
    std::vector<Comparable*> integers;

    std::string line;
    while (std::getline(inputFile, line))
    {
        int value;
        std::stringstream ss(line);

        while (ss >> value)
            integers.push_back(new Integer(value));
    }
    inputFile.close();
    
    q.quicksort(integers, 0, integers.size() - 1);

    std::ofstream outputFile("sorted_integers.txt");

    outputFile << "Sorted integers" << std::endl;
    for(int i = 0; i < integers.size(); i++)
    {
        Integer* integer = (Integer*)integers[i];
        outputFile << integer->value << std::endl;
    }
    outputFile.close();
    std::cout << "Saved sorted integers to sorted_integers.txt" << std::endl;

    std::ifstream inputPerson("persons.txt");
    std::vector<Comparable*> persons;
    
    while (std::getline(inputPerson, line))
    {
        std::stringstream ss(line);
        int age;
        std::string name;

        std::getline(ss, name, ',');
        ss >> age;
        persons.push_back(new Person(name, age));
    }

    inputPerson.close();
    q.quicksort(persons, 0, persons.size() - 1);

    std::ofstream output("sorted_persons.txt");

    output << "Sorted persons" << std::endl;
    for(int i = 0; i < persons.size(); i++)
    {
        Person* person = (Person*)persons[i];
        output << person->name << " " << person->age << std::endl;
    }
    output.close();
    std::cout << "Saved sorted persons to sorted_persons.txt";

    return 0;
}

