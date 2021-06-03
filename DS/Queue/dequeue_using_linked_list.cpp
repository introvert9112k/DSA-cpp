// in this we will implement dequeue using linked list
// in dequeue we can insert and delete from the front and rare ends
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
void push_back(int value)
{
    struct node *temp = new node;
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
void pop_back()
{
    if (front == NULL)
        cout << "the queue is empty";
    else
    {
        struct node *temp = front;
        struct node *prev = NULL;
        while (temp->next)
        {
            prev = temp;
            temp = temp->next;
        }
        if (prev == NULL)
        {
            delete rare;
            front = NULL;
        }
        else
        {
            prev->next = NULL;
            delete rare;
            rare = prev;
        }
    }
}
void push_front(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (front == NULL)
        front = temp;
    else 
    {
        temp->next = front;
        front = temp;
    }
} 
void pop_front()
{
    if(front==NULL)
        cout << "the queue is empty" << endl;
    else
    {
        struct node *temp = front;
        front = front->next;
        delete temp;
    }
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
    push_back(3);
    push_back(7);
    push_back(6);
    push_back(5);
    traverse();
    push_front(1999);
    traverse();
    pop_front();
    pop_front();
    pop_front();
    traverse();
    return 0;
} 