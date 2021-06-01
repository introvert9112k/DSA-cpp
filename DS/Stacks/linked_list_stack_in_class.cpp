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
class stack
{
public:
    node *top = NULL;
    void push(int value)
    {
        node *temp = new node;
        temp->data = value;
        temp->next = NULL;
        temp->next = top;
        top = temp;
    }
    void traverse()
    {
        node *temp = top;
        while (temp)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
    }
    int pop()
    {
        int x = -1;
        if (top != NULL)
        {

            node *last = top;
            top = last->next;
            int x = last->data;
            delete last;
        }
        return x;
    }
    int top_element()
    {  
        return top? top->data:-1;
    }
    int peek(int position)
    {
        node *temp = top;
        while(--position)
            temp = temp->next;
        return temp ? temp->data : -1;
    }
};
int main()

{
    stack s;
    s.push(9);
    s.push(8);
    s.push(7);
    // s.traverse();
    // s.pop();
    s.traverse();
   cout<<"the top element is : "<< s.top_element();
   cout << "second element is : " << s.peek(2);
   return 0;
}  