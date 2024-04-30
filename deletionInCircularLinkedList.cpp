// here we will see how to delete data from linked list (circular)
#include <iostream>
using namespace std;
class node
{
public:
    int data;
    node *next;
} *head, *tail, *temp, *newNode;
void createList();
void deleteFromBegin();
void deleteSpecific();
void deleteFromEnd();
int getLength();
void display();
int main()
{
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
void createList()
{
    head = 0;
    int choice = 1;
    while (choice)
    {
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
        cout << "\n\t\tPress 1 to continue else 0: ";
        cin >> choice;
    }
}
void deleteFromBegin()
{
    cout << "\n\t\tData will be deleted from begin" << endl;
    temp = head;
    if (temp == 0)
    {
        cout << "\n\t\tEmpty list" << endl;
    }
    else if (temp->next == head)
    {
        cout << temp->data << " is deleted " << endl;
        head = 0;
    }
    else
    {
        cout << temp->data << " is deleted " << endl;
        head = head->next;
        temp->next = 0;
        delete temp;
        tail->next = head;
    }
}
void deleteFromEnd()
{
    temp = head;
    if (temp == 0)
    {
        cout << "\n\t\tEmpty list" << endl;
    }
    else if (temp->next == head)
    {
        head = 0;
        cout << temp->data << " is deleted " << endl;
    }
    else
    {
        cout << "\n\t\tData will be deleted from end" << endl;
        while (temp->next->next != head)
            temp = temp->next;
        cout << temp->next->data << " is deleted" << endl;
        delete (temp->next);
        tail = temp;
        tail->next = head;
    }
}
void deleteSpecific()
{
    int pos;
    cout << "\n\t\tData will be deleted from specific position" << endl;
    cout << "Enter the position: ";
    cin >> pos;
    if (pos <= 0 || pos > getLength())
    {
        cout << "\t\tInvalid position" << endl;
        deleteSpecific();
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
        while (i < (pos - 1))
        {
            temp = temp->next;
            i = i + 1;
        }
        node *nextNode;
        nextNode = temp->next;
        cout << nextNode->data << " is deleted" << endl;
        temp->next = nextNode->next;
        nextNode->next = 0;
        delete nextNode;
    }
}
int getLength()
{
    int count = 0;
    temp = head;
    do
    {
        /* code */
        count++;
        temp = temp->next;
    } while (temp != head);
    return count;
}
void display()
{
    cout << endl;
    cout << "Linked List: ";
    temp = head;
    if (temp == 0)
    {
        cout << "\n\t\tEmpty list" << endl;
    }
    else
    {
        do
        {
            cout << temp->data << " ";
            temp = temp->next;
        } while (temp != head);
        cout << endl;
    }
}
