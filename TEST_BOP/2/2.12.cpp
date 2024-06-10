// Написать объявление класса linked_list, с конструктором, деструктором (нужно сделать объявления Node)

#include <iostream>
struct Node
{
    int x;
    Node* next;
};

class linked_list
{
    private:
    Node* head;

    public:
    linked_list()
    {
        head = NULL;
    }
    ~linked_list()
    {
        Node* next = head;
        while (next)
        {
            Node* current = next;
            next = next -> next;
            delete current;
        }
        
    }
};