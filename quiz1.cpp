#include <iostream>
using namespace std;
#define N 5
int stack1[N];
int stack2[N];
int top1 = -1, top2 = -1;
int count = 0;
void push1(int x)
{
    if (top1 == N - 1)
    {
        cout << "Queue is full " << endl;
        cout << endl;
    }
    else
    {
        top1++;
        stack1[top1] = x;
    }
}
int pop1()
{
    int n;
    if (top1 == -1 && top2 == -1)
    {
        cout << "NO data left " << endl;
    }
    else
    {
        n = stack1[top1--];
    }
    return n;
}
void enqueue(int x)
{
    push1(x);
    count++;
}
void push2(int x)
{
    if (top2 == N - 1)
    {
        // cout << "Stack full " << endl;
    }
    else
    {
        top2++;
        stack2[top2] = x;
    }
}
int pop2()
{
    int n;
    if (top2 == -1 && top1 == -1)
    {
        cout << "No data left" << endl;
    }
    else
    {
        n = stack2[top2--];
    }
    return n;
}
void dequeue()
{
    if (top1 == -1 && top2 == -1)
    {
        cout << "No data left" << endl;
    }
    else
    {
        int x;
        for (int i = 0; i < count; i++)
        {
            x = pop1();
            push2(x);
        }
        cout << pop2() << " is poped out " << endl;
        count--;
        for (int i = 0; i < count; i++)
        {
            x = pop2();
            push1(x);
        }
    }
}
void display()
{
    for (int i = 0; i <= top1; i++)
    {
        cout << stack1[i] << "\t";
    }
}
int main()
{
    int choice;
label:
    cout << endl;
    cout << "Press 1 to enqueue data " << endl;
    cout << "Press 2 to dequeue data " << endl;
    cout << "Press 3 to display data " << endl;
    cout << endl
         << endl;
    cout << "enter your choice ";
    cin >> choice;
    if (choice == 1)
    {
        int x;
        cout << "Enter the number ";
        cin >> x;
        enqueue(x);
    }
    else if (choice == 2)
    {
        dequeue();
    }
    else if (choice == 3)
    {
        display();
    }
    else
    {

        cout << endl;
        cout << "Invalid choice " << endl;
        exit(0);
    }
    goto label;
    return 0;
}