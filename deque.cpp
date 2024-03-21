#include <iostream>
using namespace std;
#define N 5
int deque[N];
int head = -1,
    tail = -1;
void enqueuefront(int x)
{
    if ((tail + 1) % N == head)
    {
        cout << "Dequeue is full \n"
             << endl;
    }
    else if (head == -1 && tail == -1)
    {
        head = tail = 0;
        deque[head] = x;
    }
    else if (head == 0)
    {
        head = N - 1;
        deque[head] = x;
    }
    else
    {
        head--;
        deque[head] = x;
    }
}
void enqueend(int x)
{
    if (head == -1 && tail == -1)
    {
        head = tail = 0;
        deque[tail] = x;
    }
    else if ((tail + 1) % N == head)
    {
        cout << "Queue is full" << endl;
    }
    else if (tail == N - 1)
    {
        tail = (tail + 1) % N;
        deque[tail] = x;
    }
    else
    {
        tail++;
        deque[tail] = x;
    }
}
void display()
{
    int i = head;
    if (head == -1 && tail == -1)
    {
        cout << endl
             << endl;
        cout << "Queue is empty " << endl;
    }
    else
    {
        while (i != tail)
        {
            cout << deque[i] << "\t";
            i = (i + 1) % N;
        }
        cout << deque[i] << "\t";
    }
}
void at_front()
{
    cout << endl;
    cout << "Value at front is " << deque[head] << endl;
}
void at_end()
{
    cout << endl;
    cout << "Value at end is " << deque[tail] << endl;
}
void dequeFront()
{
    if (head == -1 && tail == -1)
    {
        cout << "Deque is empty" << endl;
    }
    else if (head == tail)
    {
        cout << deque[head] << " is deleted " << endl;
        head = tail = -1;
    }
    else if (head == N - 1)
    {
        cout << deque[head] << " is deleted " << endl;
        head = (head + 1) % N;
    }
    else
    {
        cout << deque[head] << " is deleted" << endl;
        head++;
    }
}
void dequeTail()
{
    cout << endl;
    if (head == -1 && tail == -1)
    {
        cout << "Deque is empty now " << endl;
    }
    else if (tail == head)
    {
        cout << deque[tail] << " is deleted " << endl;
        tail = head = -1;
    }
    else if (tail == 0)
    {
        cout << deque[tail] << " is deleted " << endl;
        tail = N - 1;
    }
    else
    {
        cout << deque[tail] << " is deleted " << endl;
        tail--;
    }
}
int main()
{
    int choice, n;
label:
    cout << endl
         << endl;
    cout << "Enter 1 to insert value at head" << endl;
    cout << "Enter 2 to insert value at tail" << endl;
    cout << "Enter 3 to delete value at head" << endl;
    cout << "Enter 4 to delete value at tail" << endl;
    cout << "Enter 5 to see value at head" << endl;
    cout << "Enter 6 to see value at tail" << endl;
    cout << "Enter 7 to display " << endl;
    cout << "Enter 8 to exit " << endl;
    cout << "\t\tEnter your choice ==> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        cout << "\t\tEnter the number ==> ";
        cin >> n;
        enqueend(n);
        break;
    }
    case 2:
    {
        cout << "\t\tEnter the number ==> ";
        cin >> n;
        enqueuefront(n);
        break;
    }
    case 3:
    {
        dequeFront();
        break;
    }
    case 4:
    {
        dequeTail();
        break;
    }
    case 5:
    {
        at_front();
        break;
    }
    case 6:
    {
        at_end();
        break;
    }
    case 7:
    {
        display();
        break;
    }
    case 8:
    {
        cout << endl;
        cout << "Thanks" << endl;
        exit(0);
    }
    default:
    {
        cout << endl;
        cout << "Invalid choice" << endl;
    }
    }
    goto label;
    return 0;
}