#include <iostream>
using namespace std;
// class
class node
{
public:
    int data;
    node *next;
} *head, *temp, *newNode, *tail;
void createList();
void insertAtBegin();
void insertAtEnd();
void insertSpecific();
int getLength();
void display();
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
void createList()
{
    head = 0;
    int choice = 1;
    cout << "\n\t\tCreating the linked list" << endl
         << endl;
    while (choice)
    {
        /* code */
        newNode = new node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == 0)
            head = tail = newNode;
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        tail->next = head;
        cout << "\t\t\tEnter 1 to continue else 0 ): ";
        cin >> choice;
    }
}
void insertAtBegin()
{
    cout << endl
         << "\t\t\tData will be inserted at begin " << endl;
    newNode = new node;
    cout << "\tEnter the data: ";
    cin >> newNode->data;
    newNode->next = 0;
    newNode->next = head;
    head = newNode;
    tail->next = head;
}
void insertAtEnd()
{
    cout << endl
         << "\t\t\tData will be inserted at end" << endl;
    newNode = new node;
    cout << "Enter the data: ";
    cin >> newNode->data;
    newNode->next = 0;
    tail->next = newNode;
    tail = newNode;
    newNode->next = head;
}
int getLength()
{
    temp = head;
    int count = 0;
    do
    {
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void insertSpecific()
{
    cout << "\n\t\tData will be inserted at specific position" << endl;
    int pos;
    cout << "Enter the position: ";
    cin >> pos;
    cout << endl;
    cout << "Position: " << pos << "\tSize: " << getLength() << endl;
    if (pos <= 0 || pos > getLength())
    {
        cout << "\n\t\tInvalid position" << endl;
        insertSpecific();
    }
    else if (pos == 1)
        insertAtBegin();
    else
    {
        int i = 1;
        temp = head;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i = i + 1;
        }
        newNode = new node;
        cout << "Enter the data: ";
        cin >> newNode->data;
        newNode->next = 0;
        newNode->next = temp->next;
        temp->next = newNode;
    }
}
void display()
{
    temp = head;
    cout << "\n\tLinked List: ";
    do
    {
        cout << temp->data << " ";
        temp = temp->next;
    } while (temp != head);
    cout << endl;
}