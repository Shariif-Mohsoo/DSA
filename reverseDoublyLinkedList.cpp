// here we will see how to reverse the linked list via two ways.
#include <iostream>
using namespace std;
// class
class node
{
public:
    node *prev;
    int data;
    node *next;
} *head, *tail, *temp, *newNode;
// function prototypes
void createList();
void display();
void reverse();
void reverseLinks();
// main function
int main()
{
    createList();
    display();
    reverse();
    reverseLinks();
    display();
    return 0;
}
// function definitions
void createList()
{
    cout << "\n\t\tCreating the linked list" << endl;
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
void reverse()
{
    cout << "\n\tReversed Linked List: ";
    temp = tail;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->prev;
    }
    cout << endl;
}
void reverseLinks()
{
    node *nextNode;
    temp = head;
    while (temp != 0)
    {
        nextNode = temp->next;
        temp->next = temp->prev;
        temp->prev = nextNode;
        temp = nextNode;
    }
    nextNode = head;
    head = tail;
    tail = nextNode;
}
void display()
{
    cout << "\n\t";
    cout << "Linked list: ";
    temp = head;
    while (temp != nullptr)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}