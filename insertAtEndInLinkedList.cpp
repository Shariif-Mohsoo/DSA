/*
HERE WE WILL SEE HOW CAN WE INSERT THE DATA AT THE END OF THE
LINKED LIST
*/
#include <iostream>
using namespace std;
void createNodeList();
void display();
void insertAtEnd();
// creating a class
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
    insertAtEnd();
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
        cout << "Enter the integer value => ";
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
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void insertAtEnd()
{
    newNode = new node;
    cout << "Enter the integer value => ";
    cin >> newNode->data;
    newNode->next = 0;
    tail->next = newNode;
    tail = newNode;
}