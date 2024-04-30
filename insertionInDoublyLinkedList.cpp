// here we will see how to implement the doubly linked list and insert data in linked list
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
void insertAtBegin();
void insertAtEnd();
void insertSpecific();
int getLength();
// main function
int main()
{
    createList();
    display();
    insertAtBegin();
    display();
    insertAtEnd();
    display();
    insertSpecific();
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
int getLength()
{
    int count = 0;
    temp = head;
    while (temp != nullptr)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void insertAtBegin()
{
    cout << "\n\t\tData will be inserted at begin" << endl;
    newNode = new node;
    cout << "Enter the data: ";
    cin >> newNode->data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    newNode->next = head;
    head->prev = newNode;
    head = newNode;
}
void insertAtEnd()
{
    cout << "\n\t\tData will be inserted at end" << endl;
    newNode = new node;
    cout << "Enter the data: ";
    cin >> newNode->data;
    newNode->next = nullptr;
    newNode->prev = nullptr;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
}
void insertSpecific()
{
    cout << "\n\t\tData will be inserted at specific position" << endl;
    int pos;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos <= 0 || pos > getLength())
    {
        cout << "\n\tInvalid Position" << endl;
        insertSpecific();
    }
    else if (pos == 1)
    {
        insertAtBegin();
    }
    else
    {
        newNode = new node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = nullptr;
        newNode->prev = nullptr;
        temp = head;
        int i = 1;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        newNode->prev = temp;
        newNode->next = temp->next;
        temp->next = newNode;
        newNode->next->prev = newNode;
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