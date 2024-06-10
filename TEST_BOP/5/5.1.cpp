// Объясните полиморфизм на примере реализации метода void fill (linked_list* l, int value, int num)
#include <iostream>

class Node
{   
    public:
        int value;
        Node* next;
        Node(int d): value(d), next(nullptr) {}
};

class List
{
    public:
    virtual void fill(int value, int num) = 0;
};

class LinkedList : public List
{
    private:
        Node* head;

    public:
    LinkedList(): head(nullptr) {}

    void fill(int value, int num) override
    {
        for (int i = 0; i < num; i++)
            add(value);
    }

    // добавление в начало списка
    void add(int number)
    {
        Node* new_Node = new Node(number);
        new_Node->next = head;
        head = new_Node;
    }

    void display() {
        Node* temp = head;
        while (temp != nullptr) {
            std::cout << temp->value << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }

};


int main()
{
    LinkedList list;

    list.fill(5, 10);
    list.display();
}