/*
    Stack by using linked list
    so, it must be o(1) not o(n);
    In stack we follow the one rule
    which is LIFO , my mean to say that
    Last In First Out....Or........
    We can say that FILO...First IN
    Last Out...
    Like that if i have four number
    like 1....2.....3.......4......
    Okay!!!!!
    I am going to enter them in stack.
    so first numbe is 1 then 2 upto so
    on and last is four.
    when we are going to see the output
    our first is in output is 4 the number
    which we enter in the last............
    I am going to put this example in another
    way try to understand this........
    Look i have a box for bolls which we
    mosty see in shops like the cylinder okay.
    when we put balls in it the boll which we
    enter first it goes to the last and the
    boll which we enter in the last come to first
    and we can take it easily ............
    Same logic is seen in stack even though
    it is dynamically or statically.My mean
    to say that by using linked list or by
    using an array.
    The order must be o(1)..............
    Lets begin with  example of linked list
    by using stack....Let's get started.....
*/
#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *top = 0, *newNode, *temp;
void push(int x)
{
    newNode = new node;
    newNode->data = x;
    newNode->next = top;
    top = newNode;
}
void pop()
{
    if (top == 0)
    {
        cout << "\t\tDear stack is empty no data" << endl;
        // main();
    }
    else
    {
        cout << "Poped out data is " << top->data << endl;
        temp = top;
        top = temp->next;
        temp->next = 0;
        delete temp;
    }
}
void peek()
{
    if (top == 0)
    {
        cout << "\t\t\tDear Your Stack is empty " << endl;
        // main();
    }
    else
    {
        cout << top->data << " is data at peek " << endl;
    }
}
void display()
{
    temp = top;
    if (top == 0)
    {
        cout << "\t\t\tDear for your kind information stack is empty" << endl;
    }
    else
    {
        for (; temp != 0;)
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
    cout << "Press 1 to push the data " << endl;
    cout << "Press 2 to pop out the data" << endl;
    cout << "Press 3 to Peek the data " << endl;
    cout << "Press 4 to Display the data" << endl;
    cout << "Press 5 to exit " << endl;
    cout << "Enter your choice ==> ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int num;
        cout << "\t\tEnter the number ";
        cin >> num;
        push(num);
        break;
    }
    case 2:
    {
        pop();
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
        exit(0);
        break;
    }
    default:
    {
        cout << "\t\t\tInvalid choice" << endl;
    }
    }
    goto label;
    return 0;
}