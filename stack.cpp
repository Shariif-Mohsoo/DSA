#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *head = 0, *temp, *newNode;

void push_back(int x)
{
    newNode = new node;
    newNode->data = x;
    newNode->next = head;
    head = newNode;
}
void display()
{
    temp = head;
    cout << endl
         << endl;
    while (temp != 0)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void pop()
{
    if (head != 0)
    {
        temp = head;
        head = head->next;
        cout << temp->data << endl;
        cout << "\tIt is poped out" << endl;
        temp->next = 0;
        delete temp;
    }
    else
    {
        cout << "\t\tNo data is inserted in the stack" << endl;
        cout << "\t\t\tStack is empty" << endl;
    }
}
void peek()
{
    if (head != 0)
    {
        cout << head->data << endl;
        cout << "\tIt is the data at the peek or top" << endl;
    }
    else
    {
        cout << "\t\tNo data is inserted in the stack" << endl;
        cout << "\t\t\tStack is empty" << endl;
    }
}
void search()
{
    int num;
    int flag = 0;
    cout << "\tEnter the number to see it exist or not exist in the stack ==> ";
    cin >> num;
    temp = head;
    while (temp != 0)
    {
        if (temp->data == num)
        {
            flag = 1;
            break;
        }
        temp = temp->next;
    }
    if (flag)
    {
        cout << endl;
        cout << "Congrats! " << num << " exits in the stack" << endl;
    }
    else
    {
        cout << endl;
        cout << "Oops! " << num << " doesn't exist in the stack" << endl;
    }
}
int main()
{
    int choice;
label:
    cout << endl
         << endl;
    cout << "\t\tPress 1 to push data\n";
    cout << "\t\t\tPress 2 to pop data\n";
    cout << "\t\tPress 3 to peek data\n";
    cout << "\t\t\tPress 4 to display data\n";
    cout << "\t\tPress 5 to search element \n";
    cout << "\t\tPress 6 to exit \n";
    cout << "\t\t\t\tEnter your choice ==> ";
    cin >> choice;
    cout << endl
         << endl;
    switch (choice)
    {
    case 1:
    {
        int n;
        cout << "Enter the number ";
        cin >> n;
        push_back(n);
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
        search();
        break;
    }
    case 6:
    {
        cout << endl
             << endl;
        cout << "\t\t\t***(Thank's)*****" << endl;
        cout << endl;
        exit(0);
    }
    default:
    {
        cout << endl
             << endl;
        cout << "\t\tEnter the correct choice " << endl;
        cout << endl;
    }
    }
    goto label;
    return 0;
}