// in this we will implement the queue with the help of linked list
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *front = NULL, *rare = NULL;

void enqueue(int value)
{
    struct node *temp;
    temp = new node;
    if (temp == NULL)
        cout << "queue is full" << endl;
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
        cout << "the queueu is empty" << endl;
    else
    {
        struct node *temp = front;
        x = front->data;
        front = front->next;
        delete temp;
    }
    return x;
}
void traverse()
{
    struct node *temp = front;
    while (temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main()

{

    enqueue(3);
    enqueue(5);
    enqueue(10);
    traverse();
    dequeue();
    dequeue();
    traverse();
    return 0;
}