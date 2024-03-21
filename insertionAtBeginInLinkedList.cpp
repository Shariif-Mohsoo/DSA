/*
    HERE WE WILL SEE HOW CAN WE INSERT THE DATA AT THE BEGINNING OF THE
    LINKED LIST
*/
#include <iostream>
using namespace std;
// function prototype
void createNodeList();
void display();
void insertAtBegin();
// creating the class
class node
{
public:
    int data;
    node *next;
} *head, *tail, *newNode, *temp;
// main function
int main()
{
    createNodeList();
    display();
    insertAtBegin();
    display();
    return 0;
}
// function definitions
void createNodeList()
{
    head = 0;
    int choice = 1;
    while (choice == 1)
    {
        newNode = new node;
        cout << "Enter the integer number => ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head)
        {
            temp->next = newNode;
            temp = newNode;
        }
        else
        {
            head = temp = newNode;
        }
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
void insertAtBegin()
{
    cout << endl;
    cout << "\t\tEnter integer at the begin" << endl;
    newNode = new node;
    cout << "Enter the integer value => ";
    cin >> newNode->data;
    newNode->next = head;
    head = newNode;
    cout << endl;
}