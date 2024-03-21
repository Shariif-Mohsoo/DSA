/*
 HERE WE WILL SEE HOW CAN WE CREATE THE LINK LIST
*/
#include <iostream>
using namespace std;
// function prototype
void createNodeList();
void display();
// class
class node
{
public:
    int data;
    node *next;
} *head, *newNode, *temp, *tail;
// main function
int main()
{
    createNodeList();
    display();
    return 0;
}
// function definitions
void createNodeList()
{
    head = 0;
    int choice = 1;
    while (choice)
    {
        newNode = new node;
        cout << "Enter the integer number => ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == 0)
            head = temp = newNode;
        else
        {
            temp->next = newNode;
            temp = newNode;
        }
        cout << "To continue press 1 else 0 => ";
        cin >> choice;
    }
    tail = temp;
}
void display()
{
    temp = head;
    for (; temp != 0;)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
}