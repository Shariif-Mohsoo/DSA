#include<iostream>
using namespace std;

struct node
{
    int data;
    node *next;
}*temp,*tail,*newNode;

void create_list()
{
    tail = 0;
    int choice;
    do
    {
        newNode = new node;
        cout<<"Enter the number ";
        cin>>newNode->data;
        if(tail == 0)
        {
            tail = newNode;
            newNode->next = tail;
        }
        {
            newNode->next = tail->next;
            tail->next = newNode;
            tail = newNode;
        }
        cout<<"To continue press 1 ";
        cin>>choice;
    }while(choice == 1);
}
void display()
{
    temp = tail->next;
    while(temp!=0)
    {
        cout<<temp->data<<endl;
        temp = temp->next;
        if(temp == tail->next)
        break;
    }
}
void insert_at_begin()
{
    cout<<endl<<endl;
    cout<<"Data will be inserted at begin "<<endl;
    newNode = new node;
    cout<<"Enter the number ";
    cin>>newNode->data;
    newNode->next = tail->next;
    tail->next = newNode;
}
void insert_at_end()
{
    cout<<endl<<endl;
    cout<<"Data will be inserted at end "<<endl;
    newNode = new node;
    cout<<"Enter the number ";
    cin>>newNode->data;
    newNode->next = tail->next;
    tail->next = newNode;
    tail = newNode;
}
void insert_at_specific()
{
    int pos ,i =1;
    cout<<endl<<endl;
    cout<<"Data will be inserted at specific Position "<<endl;
    cout<<"Enter the position ";
    cin>>pos;
    temp = tail->next;
    for(;i<(pos-1);i++)
    {
        temp = temp->next;
    }
    newNode = new node;
    cout<<"Enter the number ";
    cin>>newNode->data;
    newNode->next = temp->next;
    temp->next = newNode;
}
void delete_at_begin()
{
    cout<<endl<<endl;
    cout<<"Data will be deleted from begin "<<endl;
    temp = tail->next;
    tail->next = temp->next;
    temp->next = 0;
    free(temp);
}
void delete_at_end()
{
    cout<<endl<<endl;
    cout<<"Data will be deleted from end "<<endl;
    temp = tail->next;
    while(temp->next!=tail)
    {
        temp = temp->next;
    }
    node *prev;
    prev = temp->next;
    temp->next = prev->next;
    tail = temp;
    free(prev);
}
void delete_at_specific()
{
    int pos;
    cout<<endl<<endl;
    cout<<"Data will be deleted from the specific position "<<endl;
    cout<<"Enter the position ";
    cin>>pos;
    temp = tail->next;
    for(int i = 1; i< (pos - 1); i++)
    {
        temp = temp->next;
    }
    node *delete_node;
    delete_node = temp->next;
    temp->next = delete_node->next;
    delete_node->next = 0;
    free(delete_node);
}
void reverse_list()
{
    cout<<endl<<endl;
    cout<<"List will be reversed "<<endl;
    node *p_node,*m_node,*n_node;
    m_node = tail->next;
    n_node = m_node->next;
    while(m_node!=tail)
    {
        p_node = m_node;
        m_node = n_node;
        n_node = m_node->next;
        m_node->next = p_node; 
    }
    n_node->next = tail;
    tail= n_node;
}
int main()
{
    create_list();
    display();
    reverse_list();
    display();
    return 0;
}