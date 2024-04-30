#include <iostream>
using namespace std;
class implementStack
{
private:
    int *stack;
    int size;
    int top;

protected:
    void push(int);
    void pop();
    void peek();
    bool isEmpty();
    void display();

public:
    implementStack();
    ~implementStack();
    void askForOperations();
};
implementStack::implementStack()
{
    size = 5;
    top = -1;
    stack = new int[size];
}
void implementStack::push(int data)
{
    if (top == size - 1)
    {
        cout << endl
             << "\t\tStack Overflow Occur" << endl;
    }
    else
    {
        top++;
        stack[top] = data;
    }
}
void implementStack::pop()
{
    if (top == -1)
    {
        cout << endl
             << "\t\tStack Underflow Occur" << endl;
    }
    else
    {
        cout << stack[top] << " is pop out" << endl;
        top--;
    }
}
void implementStack::peek()
{
    if (top == -1)
        cout << "\n\t\tEmpty Stack" << endl;
    else
        cout << stack[top] << " is at top position." << endl;
}
bool implementStack::isEmpty()
{
    if (top == -1)
        return true;
    else
        return false;
}
void implementStack::display()
{
    if (top == -1)
    {
        cout << endl
             << "Empty Stack" << endl;
    }
    else
    {
        cout << endl
             << "Stack values: ";
        for (int i = top; i >= 0; i--)
            cout << stack[i] << " ";
        cout << endl;
    }
}
void implementStack::askForOperations()
{
    cout << endl
         << endl;
    int choice;
    cout << "\n\t\t==========================================" << endl;
    cout << "\t\t|\tEnter 1 for push operation        |" << endl;
    cout << "\t\t|\tEnter 2 for pop  operation        |" << endl;
    cout << "\t\t|\tEnter 3 for peek operation        |" << endl;
    cout << "\t\t|\tEnter 4 for check operation       |" << endl;
    cout << "\t\t|\tEnter 5 for display               |" << endl;
    cout << "\t\t==========================================" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    // lets begin
    switch (choice)
    {
    case 1:
    {
        int item;
        cout << "\n\t\tEnter the value: ";
        cin >> item;
        this->push(item);
        break;
    }
    case 2:
    {
        this->pop();
        break;
    }
    case 3:
    {
        this->peek();
        break;
    }
    case 4:
    {
        bool isTrue = this->isEmpty();
        if (isTrue)
            cout << "\n\t\tStack is empty" << endl;
        else
            cout << "\n\t\tStack is not empty" << endl;
        break;
    }
    case 5:
    {
        this->display();
        break;
    }
    default:
    {
        cout << "\n\t\tInvalid choice" << endl;
        askForOperations();
    }
    }
    cout << "\n\t\tTo continue press 1 else 0: ";
    cin >> choice;
    if (choice)
        askForOperations();
    else
        cout << "\n\t\tThnks Dear" << endl;
}
implementStack::~implementStack()
{
    delete[] stack;
}
int main()
{
    implementStack s;
    s.askForOperations();
    return 0;
}