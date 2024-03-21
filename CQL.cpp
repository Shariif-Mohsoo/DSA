/*
    Hello you beautiful people how are you, here
    you can see how the circular queue is implemented
    by using the linked list.....
    Basically it same behaves like circular linked list
    because it we have to make the circular of the queue
    or circular queue, so through linked listed it is
    implemented same as the circular linked list is
    implemented.....
*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *head = 0, *tail = 0, *newNode, *temp;
void enQueue(int x)
{
    newNode = new node;
    newNode->data = x;
    newNode->next = 0;
    if (head == 0 && tail == 0)
    {
        head = tail = newNode;
        tail->next = head;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
        tail->next = head;
    }
}
void deQueue()
{
    if (head == 0 && tail == 0)
    {
        cout << endl;
        cout << "\t\tQueue is empty" << endl;
    }
    else if (head == tail)
    {
        head = tail = 0;
    }
    else
    {
        cout << "\n\t\t The deQueue data is " << head->data << endl;
        temp = head;
        head = temp->next;
        tail->next = head;
        temp->next = 0;
        free(temp);
    }
}
void peek()
{
    if (head == 0 && tail == 0)
    {
        cout << "\t\tQueue is empty " << endl;
    }
    else
    {
        cout << "Data at the peek is " << head->data << endl;
    }
}
void display()
{
    if (head == 0 && tail == 0)
    {
        cout << "\t\tQueue is empty " << endl;
    }
    else
    {
        temp = head;
        for (; temp->next != head;)
        {
            cout << temp->data << "\t";
            temp = temp->next;
        }
        cout << temp->data << endl;
    }
}
// driver program or function
int main()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\tEnter 1 to enqueue data " << endl;
    cout << "\tEnter 2 to dequeue data " << endl;
    cout << "\tEnter 3 to peek data " << endl;
    cout << "\t\tEnter 4 to display data " << endl;
    cout << "\t\t\tEnter 5 to exit " << endl;
    cout << "\n\n\t\tEnter your choice === ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
    case 1:
    {
        int n;
        cout << "\n\t\tEnter the number ";
        cin >> n;
        enQueue(n);
        break;
    }
    case 2:
    {
        deQueue();
        break;
    }
    case 3:
    {
        peek();
        break;
    }
    case 4:
    {
        display();
        break;
    }
    case 5:
    {
        cout << endl;
        cout << "\t\t(((Thanks)))";
        cout << endl;
        exit(0);
    }
    default:
    {
        cout << "\t\tDear You are not blind, so read carefully ==Invalid_Choice==> " << endl;
    }
    }
    goto label;
    return 0;
}