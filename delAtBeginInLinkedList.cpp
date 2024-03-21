/*
HERE WE WILL SEE HOW CAN WE DELETE THE NODE FROM THE
BEGINNING OF THE LIST
*/
#include <iostream>
using namespace std;
// function prototypes
void createList();
void display();
void deleteFromBegin();
// creating the class
class node
{
public:
    int data;
    node *next;
} *head, *tail, *temp, *newNode;
int main()
{
    createList();
    display();
    deleteFromBegin();
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
    cout << endl;
}
void deleteFromBegin()
{
    temp = head;
    cout << endl;
    cout << temp->data << " is deleted successfully" << endl;
    head = head->next;
    delete temp;
}