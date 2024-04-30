#include <iostream>
using namespace std;
class implementQueue
{
private:
    int *queue;
    int size;
    int rear;
    int front;

protected:
    void enQueue(int);
    void deQueue();
    void display();
    void peek();

public:
    implementQueue();
    void performOperations();
};
implementQueue::implementQueue()
{
    cout << "Enter the size of queue: ";
    cin >> size;
    queue = new int[size];
    front = rear = -1;
}
void implementQueue::enQueue(int data)
{
    cout << endl;
    if (rear == size - 1)
        cout << "Overflow occur" << endl;
    else if (front == -1 && rear == -1)
    {
        front = rear = 0;
        queue[rear] = data;
    }
    else
    {
        rear++;
        queue[rear] = data;
    }
}
void implementQueue::deQueue()
{
    if (rear == -1 && front == -1)
    {
        cout << "Underflow occur" << endl;
    }
    else if (front == rear)
    {
        cout << queue[front] << " is dequeued" << endl;
        front = rear = -1;
    }
    else
    {
        cout << queue[front] << " is dequeued" << endl;
        front++;
    }
}
void implementQueue::peek()
{
    if (rear == -1 && front == -1)
    {
        cout << "Overflow occur" << endl;
    }
    else
    {
        cout << queue[front] << " is at the top position" << endl;
    }
}
void implementQueue::display()
{
    if (front == -1 && rear == -1)
    {
        cout << endl;
        cout << "Empty Queue" << endl;
    }
    else
    {
        cout << "Queue: ";
        for (int i = front; i <= rear; i++)
            cout << queue[i] << " ";
        cout << endl;
    }
}
void implementQueue::performOperations()
{
    cout << endl;
    cout << endl;
    int choice;
    cout << "Enter 1 to enqueue" << endl;
    cout << "Enter 2 to dequeue" << endl;
    cout << "Enter 3 to check peek" << endl;
    cout << "Enter 4 to display" << endl;
    cout << "Enter your choice: ";
    cin >> choice;
    switch (choice)
    {
    case 1:
    {
        int item;
        cout << "\t\tEnter the data: ";
        cin >> item;
        this->enQueue(item);
        break;
    }
    case 2:
    {
        this->deQueue();
        break;
    }
    case 3:
    {
        this->peek();
        break;
    }
    case 4:
    {
        this->display();
        break;
    }
    default:
    {
        cout << "\t\tInvalid Input" << endl;
        this->performOperations();
        break;
    }
    }
    cout << "\n\t\t To continue press 1 else 0: ";
    cin >> choice;
    if (choice)
        this->performOperations();
    else
    {
        cout << "\n\t\tThanks Dear" << endl;
        exit(0);
    }
}
int main()
{
    implementQueue queue;
    queue.performOperations();
    return 0;
}