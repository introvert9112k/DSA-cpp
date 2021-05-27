// problem statement
// reverse a linked list
// first we will create a linked list and reverse it
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *last = NULL;
void append(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        last = temp;
    }
}
void traverse()
{
    struct node *current = head;
    while (current)
    {
        cout << current->data<<" ";
        current = current->next;
    }
}
void reverse()
{
    struct node *third = NULL, *second = NULL, *first = head;
    while (first)
    {
        third = second;
        second = first;
        first = first->next;
        second->next = third;
    }
    last = head;
    head = second;
}
int main()

{
    append(3);
    append(4);
    append(5);
    traverse();
    reverse();
    append(100);
    traverse();
    
    return 0; 
} 