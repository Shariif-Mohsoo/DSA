#include <iostream>
#define N 5
using namespace std;
int s1[N];
int s2[N];
int count = 0;
int head1 = -1;
int head2 = -1;
void push1(int);
void push2(int);
int pop1();
int pop2();
void enQueue(int x)
{
    push1(x);
    count++;
}
void push1(int data)
{
    if (head1 == N - 1)
    {
        cout << "\nNo space left in the queue" << endl;
    }
    else if (head1 == -1)
    {
        head1 = 0;
        s1[head1] = data;
    }
    else
    {
        head1++;
        s1[head1] = data;
    }
}
int pop1()
{
    int n = head1--;
    return s1[n];
}
void deQueue()
{
    int x;
    for (int i = 0; i < count; i++)
    {
        x = pop1();
        push2(x);
    }
    cout << pop2() << " is dequeued " << endl;
    count--;
    for (int i = 0; i < count; i++)
    {
        x = pop2();
        push1(x);
    }
}
int pop2()
{
    int n = head2--;
    return s2[n];
}
void push2(int data)
{
    if (head2 == N - 1)
    {
        cout << "\nNo space left in the queue" << endl;
    }
    else if (head2 == -1)
    {
        head2 = 0;
        s2[head2] = data;
    }
    else
    {
        head2++;
        s2[head2] = data;
    }
}
void display()
{
    cout << "The data in the queue is " << endl;
    if (head1 == -1)
    {
        cout << "\tNull " << endl;
    }
    else
    {
        for (int i = 0; i <= head1; i++)
        {
            cout << s1[i] << "\t";
        }
    }
}
int main()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\tEnter 1 to enter data " << endl;
    cout << "\tEnter 2 to delete data " << endl;
    cout << "\t\tEnter 3 to display data" << endl;
    cout << "\tEnter 4 to exit " << endl;
    cout << "\n\t\t\tEnter your choice ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
        /* code */
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
        display();
        break;
    }
    case 4:
    {
        cout << "\t\t(((Thanks)))" << endl;
        exit(0);
    }
    default:
        cout << "\t\tInvalid choice " << endl;
        break;
    }
    goto label;
    return 0;
}