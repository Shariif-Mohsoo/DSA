#include <iostream>
using namespace std;
// function prototypes
void createList();
void display();
void deleteSpecific();
// class
class node
{
public:
    int data;
    node *next;
} *head, *temp, *tail, *newNode;
int count = 0;
int main()
{
    createList();
    display();
    deleteSpecific();
    display();
    return 0;
}
// function definitions
void createList()
{
    head = 0;
    int choice = 1;
    while (choice)
    {
        newNode = new node;
        cout << "Enter the data => ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == 0)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        count++;
        cout << "To continue press 1 else 0 => ";
        cin >> choice;
    }
    tail = temp;
}
void display()
{
    temp = head;
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteSpecific()
{
    int pos;
    cout << "Enter the position => ";
    cin >> pos;
    if (pos > count)
        cout << "Invalid" << endl;
    else
    {
        int i = 1;
        node *nextNode;
        temp = head;
        while (i < (pos - 1))
        {
            temp = temp->next;
            i++;
        }
        nextNode = temp->next;
        temp->next = nextNode->next;
        cout << endl;
        cout << nextNode->data << " is deleted successfully " << endl;
        nextNode->next = 0;
        delete nextNode;
    }
}