#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node* nextPointer;
};

class LinkedList
{
    Node* head;
public:

    LinkedList()
    {
        head = nullptr;
    }
    LinkedList(initializer_list<int> list)
    {
        head = nullptr;
        for(const int* i = list.begin(); i != list.end(); i++)
        {
            addNode(*i);

        }
    }
     Node* newNode(int data)
    {
        Node*  temp = new Node();
        temp->data = data;
        temp-> nextPointer = nullptr;
        return temp;
    }

   void addNode(int data)
    {
       if(head == nullptr)
       {
           head = newNode(data);
       }
        else
        {
            Node* temp = head;
            while(temp->nextPointer != nullptr)
            {
                temp= temp->nextPointer;

            }
            temp->nextPointer = newNode(data);
        }
    }

    void display()
    {
        Node* temp = head;
        while(temp != nullptr)
        {
            cout<<temp->data<<" --> ";
            temp= temp->nextPointer;

        }
    }
}
int main()
{

    LinkedList l = {1,2,3,4,5};
    // l.addNode(10);
    // l.addNode(20);
    // l.addNode(30);
    l.display();

}
