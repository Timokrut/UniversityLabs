#include <iostream>

class Node
{
    public:
    int data;
    Node* next;

    Node(int value): data(value), next(nullptr) {}
};

class Linked_list
{
    private:
        Node* head;

    public:
        Linked_list(): head(nullptr) {}
        ~Linked_list()
        {
            while (head)
            {
                Node* temp = head;
                head = head->next;
                delete temp;
            }
        }
        
        void push_back(int value)
        {
            Node* new_node = new Node(value);
            if (!head)
                head = new_node;
            else
            {
                Node* current = head;
                while (current->next)
                    current = current->next;

                current->next = new_node;                
            }    
        }
        void insert(int index, int value)
        {
            if (index < 0) return;
            Node* new_node = new Node(value);

            if (index == 0)
            {
                new_node->next = head;
                head = new_node;
                return;
            }

            Node* current = head;
            for (int i = 0; (current) && (i < index - 1); i++)
                current = current->next;
            
            if (current)
            {
                new_node->next = current->next;
                current->next = new_node;
            }
            else
                delete new_node; // index out of range
        }

        void erase(int index)
        {
            if (index < 0 || !head) return;
            
            Node* temp;
            if (index == 0)
            {
                temp = head;
                head = temp->next;
                delete temp;
                return;
            }

            Node* current = head;
            for (int i = 0; current->next && i < index - 1; i++)
                current = current->next;

            if (current->next)
            {
                temp = current->next;
                current->next = current->next->next;
                delete temp;
            }
        }

        void set(int index, int value)
        {
            Node* current = head;
            for (int i = 0; current && i < index - 1; i++)
                current = current->next;

            if (current)
            {
                current->data = value;
            }            
        }

        int get(int index)
        {
            Node* current = head;
            for (int i = 0; current && i < index - 1; i++)
                current = current->next;

            if(current)
            {
                return current->data;
            }

            return -1; // Index not found                
        }     

        int find(int number)
        {
            Node* current = head;
            int index = 0;
            while (current)
            {
                if (current->data == number)
                    return index;
                current = current->next;
                index++;    
            }
            return -1; // Number not found
        }
        void print()
        {
            Node* current = head;
            while (current)
            {
                std::cout<< current->data << " ";
                current = current->next;
            }
            std::cout<<""<<std::endl;
        }
};

int main()
{
    Linked_list list;
    list.push_back(1);
    list.push_back(2);
    list.push_back(3);
    list.push_back(4);
    list.push_back(5);

    list.print();

    list.insert(2, 10);
    list.print();

    int index = list.find(5);
    std::cout << index << std::endl;

    list.erase(0);
    list.erase(2);
    list.erase(3);

    list.print();

    int number = list.get(0);
    std::cout << number << std::endl;

    list.set(0, 52);
    list.print();

    list.~Linked_list();

    list.print();



}