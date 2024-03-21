#include <iostream>
#define N 5
using namespace std;
// methods
int queue[N];
int head = -1;
int tail = -1;
void enQueue(int x)
{
    if (head == -1 && tail == -1)
    {
        head = tail = 0;
        queue[tail] = x;
    }
    else if ((tail + 1) % N == head)
    {
        cout << "\t\tQueue is full " << endl;
    }
    else
    {
        tail = (tail + 1) % N;
        queue[tail] = x;
    }
}
void deQueue()
{
    if (head == -1 && tail == -1)
    {
        cout << "\t\tThe queue is empty " << endl;
    }
    if (head == tail)
    {
        head = tail = -1;
    }
    else
    {
        cout << queue[head] << " is poped out" << endl;
        head = (head + 1) % N;
    }
}
void peek()
{
    if (head == -1 && tail == -1)
    {
        cout << "\tThe queue is empty " << endl;
    }
    else
    {
        cout << endl;
        cout << queue[head] << " is at peek " << endl;
    }
}
void display()
{
    if (head == -1 && tail == -1)
    {
        cout << "\t\tThe queue is empty " << endl;
    }
    else
    {
        int i = head;
        while (i != tail)
        {
            cout << queue[i] << "\t";
            i = (i + 1) % N;
        }
        cout << queue[i] << "\t";
    }
}
int main()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\tEnter 1 to Enqueue the data " << endl;
    cout << "\tEnter 2 to Dequeue the data " << endl;
    cout << "\t\tEnter 3 to Peek the data " << endl;
    cout << "\tEnter 4 to display the data " << endl;
    cout << "\t\tEnter 5 to exit " << endl;
    cout << "\t\tDear enter your choice ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int n;
        cout << "\tEnter the number ";
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
        cout << "\t\tThanks" << endl;
        exit(0);
    }
    default:
    {
        cout << endl
             << endl;
        cout << "\t\tInvalid choice " << endl;
    }
    }
    goto label;
    return 0;
}