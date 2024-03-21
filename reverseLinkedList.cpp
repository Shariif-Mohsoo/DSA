/*
HERE WE WILL SEE HOW CAN WE REVERSE THE LINKED LIST
*/
#include <iostream>
using namespace std;
// function prototype
void createList();
void display();
void reverse();
// class
class node
{
public:
    int data;
    node *next;
} *head, *temp, *newNode;
int main()
{
    createList();
    display();
    reverse();
    display();
    return 0;
}
void createList()
{
    head = nullptr;
    int choice = 1;
    while (choice)
    {
        newNode = new node;
        cout << "Enter the number => ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == nullptr)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "To continue press 1 else 0 => ";
        cin >> choice;
    }
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
void reverse()
{
    node *preNode, *currentNode, *nextNode;
    preNode = 0;
    currentNode = nextNode = head;
    while (nextNode != 0)
    {
        nextNode = nextNode->next;
        currentNode->next = preNode;
        preNode = currentNode;
        currentNode = nextNode;
    }
    head = preNode;
}