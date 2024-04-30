// here we will see how to implement the doubly linked list
#include <iostream>
using namespace std;
// class
class node
{
public:
    node *prev;
    int data;
    node *next;
} *head, *tail, *newNode, *temp;
// function
void createList();
void display();
// main function
int main()
{
    createList();
    display();
    return 0;
}
// function body
void createList()
{
    cout << endl
         << "\t\tCreating the linked list" << endl;
    head = nullptr;
    int choice = 1;
    while (choice)
    {
        newNode = new node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->prev = nullptr;
        newNode->next = nullptr;
        if (head == nullptr)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        cout << "\n\t\tTo continue press 1 else 0: ";
        cin >> choice;
    }
}
void display()
{
    cout << endl;
    cout << "Linked List: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}