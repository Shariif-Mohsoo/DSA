/*
HERE WE WILL SEE HOW CAN WE DELETE THE NODE FROM THE END
OF THE LIST
*/
#include <iostream>
using namespace std;
void createList();
void display();
void deleteFromEnd();
class node
{
public:
    int data;
    node *next;
} *head, *temp, *newNode, *tail;
int main()
{
    createList();
    display();
    deleteFromEnd();
    display();
    return 0;
}
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
    while (temp != 0)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
void deleteFromEnd()
{
    node *preNode;
    temp = head;
    while (temp->next != 0)
    {
        preNode = temp;
        temp = temp->next;
    }
    cout << endl;
    cout << temp->data << " is deleted successfully " << endl;
    preNode->next = 0;
    delete temp;
}