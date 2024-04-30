#include <iostream>
using namespace std;
class node
{
    int data;
    node *next;
    friend class implementStack;
};
class implementStack
{
private:
    node *top;
    node *temp;
    node *newNode;

protected:
    void push(int);
    void pop();
    void peek();
    void display();

public:
    implementStack();
    void implementMethods();
    ~implementStack();
};
implementStack::implementStack()
{
    top = nullptr;
}
void implementStack::push(int data)
{
    newNode = new node;
    newNode->data = data;
    newNode->next = top;
    top = newNode;
}
void implementStack::pop()
{
    if (top == nullptr)
    {
        cout << "\n\t\tThe stack is empty" << endl;
    }
    else
    {
        temp = top;
        cout << temp->data << " is pop out" << endl;
        top = top->next;
        temp->next = nullptr;
        delete temp;
    }
}
void implementStack::peek()
{
    if (top == 0)
    {
        cout << "\n\t\tThe stack is empty" << endl;
    }
    else
    {
        cout << top->data << " is at top position" << endl;
    }
}
void implementStack::display()
{
    if (top == 0)
    {
        cout << "\n\t\tEmpty Stack" << endl;
    }
    else
    {
        cout << "\n\t\tStack data: ";
        temp = top;
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
}
void implementStack::implementMethods()
{
    int choice;
    cout << endl
         << endl;
    cout << "\t\tEnter 1 to push data" << endl;
    cout << "\t\tEnter 2 to pop data" << endl;
    cout << "\t\tEnter 3 to peek data" << endl;
    cout << "\t\tEnter 4 to display data" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
    case 1:
    {
        int item;
        cout << "\n\tEnter the value: ";
        cin >> item;
        push(item);
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
    default:
    {
        cout << "\n\t\tInvalid input" << endl;
        implementMethods();
    }
    }
    cout << "\n\t\tTo continue press 1 else 0 : ";
    cin >> choice;
    if (choice == 1)
        implementMethods();
    else
        cout << "\n\tThanks Dear" << endl;
}
implementStack::~implementStack()
{
    delete newNode;
}
int main()
{
    implementStack stack;
    stack.implementMethods();
    return 0;
}