#include <iostream>
using namespace std;
struct node
{
    int data;
    node *next;
} *head, *tail, *newNode, *temp;
void create_list()
{
    head = 0;
    int choice;
    do
    {
        newNode = new node;
        cout << "Enter the number ";
        cin >> newNode->data;
        newNode->next = 0;
        if (head == 0)
        {
            tail = head = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }
        cout << "To contine Press 1 ";
        cin >> choice;
    } while (choice == 1);
}
void display()
{
    temp = head;
    for (; temp != 0;)
    {
        cout << temp->data << endl;
        temp = temp->next;
    }
}
void deleteBegin()
{
    cout << endl;
    cout << "Data will be deleted from the begin" << endl;
    temp = head;
    head = temp->next;
    temp->next = 0;
    delete temp;
}
void deleteEnd()
{
    cout << endl;
    cout << "Data will be deleted from the end" << endl;
    temp = head;
    node *prev;
    for (; temp->next != 0;)
    {
        prev = temp;
        temp = temp->next;
    }
    prev->next = 0;
    tail = prev;
    delete temp;
}
void deleteSpecific()
{
    cout << endl;
    cout << "Data will be deleted form the specific position ";
    int pos;
    cout << "Enter the position ";
    cin >> pos;
    temp = head;
    for (int i = 1; i < pos - 1; i++)
    {
        temp = temp->next;
    }
    node *middle;
    middle = temp->next;
    temp->next = middle->next;
    middle->next = 0;
    delete middle;
}
void search()
{
    cout << endl;
    cout << "Data will be searched for you " << endl;
    int num;
    cout << "Enter the number  ";
    cin >> num;
    temp = head;
    int flag = 0;
    for (; temp != 0;)
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
        cout << "Data exists in the list " << endl;
    }
    else
    {
        cout << "Data doesn't exist in the list" << endl;
    }
}
void reverse()
{
    cout << endl;
    cout << "The revere of the list is" << endl;
    node *p_node, *m_node, *n_node;
    p_node = 0;
    m_node = n_node = head;
    while (m_node != 0)
    {
        n_node = n_node->next;
        m_node->next = p_node;
        p_node = m_node;
        m_node = n_node;
    }
    head = p_node;
}
int main()
{
    create_list();
    display();
    // deleteEnd();
    // display();
    // deleteBegin();
    // display();
    // deleteSpecific();
    // display();
    reverse();
    display();
    return 0;
}