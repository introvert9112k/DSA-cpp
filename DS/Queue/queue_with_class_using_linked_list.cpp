// in this we will implement the queue with the help of linked list using the class
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class node
{
public:
    int data;
    node *next;
};
class queue
{
    node *front = NULL;
    node *rare = NULL;

public:
    void enqueue(int value)
    {
        node *temp = new node;
        if (temp == NULL)
            cout << "the queue is full" << endl;
        else
        {
            temp->data = value;
            temp->next = NULL;
            if (front == NULL)
            {
                front = temp;
                rare = temp;
            }
            else
            {
                rare->next = temp;
                rare = temp;
            }
        }
    }
    int dequeue()

    {
        int x = -1;
        if (front == NULL)
            cout << "the queue is empty" << endl;
        else
        {
            node *temp = front;
            x = front->data;
            front = front->next;
            delete temp;
        }
        return x;
    }
    void traverse()
    {
        node *temp = front;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }
};
int main()

{
    queue q;
    q.enqueue(2);
    q.enqueue(5);
    q.enqueue(10);
    q.traverse();
    q.dequeue();
    q.dequeue();
    q.traverse();
    return 0;
} 