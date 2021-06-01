#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *top = NULL, *last = NULL;

void push(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if(top == NULL)
    {
        top = temp;
        last = temp;
    }
    else
    {
        temp->next = last;
        top = temp;
        last = temp;
    }
} 
int pop()
{
    int x = -1;
    if(top!=NULL)
    {
        x = top->data;
        top = last->next;
        last->next = NULL;
        delete last;
        last = top;
    }
    return x;
} 
void traverse()
 {
     struct node *temp = top;
     while(temp)
     {
         cout << temp->data << " ";
         temp = temp->next;
     }
 }

int top_element()
{
    if(top!=NULL)
        return top->data;
    return -1;
} 

int peek(int position)
{
    struct node *temp = top;
    while(--position)
        temp = temp->next;
    return temp ? temp->data : -1;
}
int main() 

{

    push(3);
    push(4);
    push(5);
    push(8);
    push(9);
    // pop();


    return 0;
} 