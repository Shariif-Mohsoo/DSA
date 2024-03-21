#include <iostream>
using namespace std;
struct node
{
    node *prev;
    int data;
    node *next;
} *head, *tail, *temp, *newNode;
void create_list()
{
    head = 0;
    int choice;
    do
    {
        newNode = new node;
        cout << "Enter the number  ";
        cin >> newNode->data;
        if (head == 0)
        {
            head = tail = newNode;
            newNode->next = newNode->prev = head;
        }
        else
        {
            newNode->prev = tail;
            tail->next = newNode;
            newNode->next = head;
            head->prev = newNode;
            tail = newNode;
        }
        cout << "To continue press 1 ";
        cin >> choice;
    } while (choice == 1);
}
void display()
{
    temp = head;
    while (temp != tail)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
    cout << temp->data << endl;
}
void insert_at_begin()
{
    cout << endl
         << endl;
    cout << "Data will be inserted at begin" << endl;
    newNode = new node;
    cout << "Enter the number  ";
    cin >> newNode->data;
    head->prev = newNode;
    newNode->next = head;
    head = newNode;
    head->prev = tail;
    tail->next = head;
}
void insert_at_end()
{
    cout << endl
         << endl;
    cout << "Data will be inserted at end " << endl;
    newNode = new node;
    cout << "Enter the number ";
    cin >> newNode->data;
    tail->next = newNode;
    newNode->prev = tail;
    tail = newNode;
    head->prev = tail;
    tail->next = head;
}
void insert_at_specific()
{
    cout << endl
         << endl;
    cout << "Data will be inserted at specific position " << endl;
    int pos;
    cout << "Enter the position ";
    cin >> pos;
    pos--;
    newNode = new node;
    cout << "Enter the number ";
    cin >> newNode->data;
    temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    newNode->next = temp->next;
    newNode->prev = temp;
    temp->next->prev = newNode;
    temp->next = newNode;
}
void delete_begin()
{
    cout << endl
         << endl;
    cout << "The data will be deleted from begin" << endl;
    temp = head;
    head = temp->next;
    head->prev = tail;
    tail->next = head;
    free(temp);
}
void delete_end()
{
    cout << endl
         << endl;
    cout << "The data will be deleted from end " << endl;
    temp = tail;
    tail = temp->prev;
    tail->next = head;
    head->prev = tail;
    free(temp);
}
void delete_specific()
{
    cout << endl
         << endl;
    cout << "Data will be deleted form specific position";
    cout << endl;
    int pos, i = 1;
    cout << "Enter the position ";
    cin >> pos;
    newNode = new node;
    temp = head;
    for (int i = 1; i < pos; i++)
        temp = temp->next;
    temp->next->prev = temp->prev;
    temp->prev->next = temp->next;
    free(temp);
}
void reverse()
{
    cout << "The reverse of the list is" << endl;
    temp = tail;
    while (temp != head)
    {
        cout << temp->data << endl;
        temp = temp->prev;
        if (temp == head)
        {
            cout << temp->data << endl;
            exit(0);
        }
    }
}
int main()
{
    create_list();
    display();
    reverse();
    display();
    return 0;
}