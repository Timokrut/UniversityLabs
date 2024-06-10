// Вывести класс Person(имя и возраст) а затем класс worker (имя,возраст, размер зарплаты и стаж работы)

#include <iostream>

class Person
{
    protected:
        char* name;
        int age;

    public:
        Person(char* Name, int Age): name(Name), age(Age) {}

        virtual ~Person() = default;
};

class Worker : public Person
{
    protected:
        double salary;
        double experience;

    public:
        Worker(char* name, int age, double W_salary, double W_experience) : Person(name, age), salary(W_salary), experience(W_experience) {}

        double calculate_salary() const
        {
            return salary;
        }  

        double calculate_expierence() const
        {
            return experience;
        }
};