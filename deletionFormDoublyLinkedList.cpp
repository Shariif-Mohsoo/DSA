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
int getLength();
void display();
void deleteFromBegin();
void deleteFromEnd();
void deleteSpecific();
// main function
int main()
{
    // invoking the function
    createList();
    display();
    deleteFromBegin();
    display();
    deleteFromEnd();
    display();
    deleteSpecific();
    display();
    return 0;
}
// function definitions
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
        cout << "\t\tEnter 1 to continue else 0: ";
        cin >> choice;
    }
}
void deleteFromBegin()
{
    if (head == nullptr)
    {
        cout << endl
             << "\t\tEmpty list" << endl;
    }
    else
    {
        cout << endl
             << "\t\tData will be deleted from begin" << endl;
        temp = head;
        cout << "\n\t" << head->data << " is deleted" << endl;
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
    }
}
void deleteFromEnd()
{
    if (head == nullptr)
    {
        cout << endl;
        cout << "\t\tEmpty list" << endl;
    }
    else
    {
        cout << endl
             << "\t\tData will be deleted from end" << endl;
        temp = tail;
        cout << "\n\t\t" << temp->data << " is deleted" << endl;
        tail = tail->prev;
        tail->next = nullptr;
        temp->prev = nullptr;
        delete temp;
    }
}
void deleteSpecific()
{
    cout << "\n\t\t Data will be deleted form the specific position" << endl;
    int pos;
    cout << "\n\tEnter the position: ";
    cin >> pos;
    if (head == nullptr)
    {
        cout << "\n\t\tEmpty list" << endl;
    }
    else if (pos == 1)
    {
        deleteFromBegin();
    }
    else if (pos == getLength())
    {
        deleteFromEnd();
    }
    else
    {
        temp = head;
        int i = 1;
        while (i < pos)
        {
            temp = temp->next;
            i++;
        }
        cout << "\n\t\t" << temp->data << " is deleted" << endl;
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;
        temp->next = temp->prev = nullptr;
        delete temp;
    }
}
int getLength()
{
    int count = 0;
    cout << "Linked List: ";
    temp = head;
    while (temp != nullptr)
    {
        /* code */
        count++;
        temp = temp->next;
    }
    return count;
}
void display()
{
    if (head == nullptr)
    {
        cout << endl;
        cout << "Empty list" << endl;
    }
    else
    {
        cout << endl;
        cout << "Linked List: ";
        temp = head;
        while (temp != nullptr)
        {
            /* code */
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    cout << endl;
}
