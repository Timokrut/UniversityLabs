// Объясните полиморфизм на примере классов Worker и Developer (размер зп, размер премии)

#include <iostream>
class Worker
{
    protected:
        std::string name;
        int age;
    public:
        Worker(std::string& W_name, int W_age):name(W_name), age(W_age) {};

        virtual double count_salary() const = 0;
        virtual double count_bonus() const = 0;

        virtual ~Worker() = default;
};

class Developer : public Worker
{
    private:
        double Dev_salary;
        double Dev_bonus;
    public:
        Developer(std::string& Dev_name, int Dev_age, double salary, double bonus): Worker(Dev_name, Dev_age), Dev_salary(salary), Dev_bonus(bonus) {};
        
        double count_salary() const override 
        {
            return Dev_salary;
        }

        double count_bonus() const override
        {
            return Dev_bonus;
        }
};


int main()
{
    std::string name = "Timofey";
    Developer dev(name, 19, 350000, 50000);

    return 0;
}