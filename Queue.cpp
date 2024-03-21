#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *temp, *head = 0, *tail = 0, *newNode;
void enQueue(int x)
{
    newNode = new node;
    newNode->data = x;
    newNode->next = 0;
    if (head == 0 && tail == 0)
    {
        head = tail = newNode;
    }
    else
    {
        tail->next = newNode;
        tail = newNode;
    }
}
void deQueue()
{
    if (head == 0 && tail == 0)
    {
        cout << "\t\tThe queue is empty " << endl;
    }
    else
    {
        cout << head->data << " is poped out" << endl;
        temp = head;
        head = temp->next;
        temp->next = 0;
        delete temp;
    }
}
void peek()
{
    if (tail == 0 && head == 0)
    {
        cout << "\t\tQueue is empty " << endl;
    }
    else
    {
        cout << "The data at the top is " << head->data << endl;
    }
}
void display()
{
    if (tail == 0 && head == 0)
    {
        cout << "\t\tQueue is empty " << endl;
    }
    else
    {
        temp = head;
        while (temp != 0)
        {
            cout << temp->data << endl;
            temp = temp->next;
        }
    }
}
int main()
{
    int choice;
label:
    cout << "\t\tEnter 1 to enqueue data " << endl;
    cout << "\tEnter 2 to dequeue data " << endl;
    cout << "\t\tEnter 3 to peek data " << endl;
    cout << "\tEnter 4 to display data " << endl;
    cout << "\t\tEnter 5 to exit " << endl;
    cout << "\t\t\tEnter your choice ====>";
    cin >> choice;
    if (choice == 1)
    {
        cout << endl;
        int x;
        cout << "\t\t\tEnter the number ";
        cin >> x;
        enQueue(x);
    }
    else if (choice == 2)
    {
        deQueue();
    }
    else if (choice == 3)
    {
        peek();
    }
    else if (choice == 4)
    {
        display();
    }
    else if (choice == 5)
    {
        cout << "\t\t\tThanks" << endl;
        exit(0);
    }
    else
    {
        cout << endl;
        cout << "\t\tDear Invalid Choice " << endl;
    }
    goto label;
    return 0;
}