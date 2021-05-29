// in this we will look at the double linked list
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct node
{
    struct node *previous;
    int data;
    struct node *next;
};
struct node *head = NULL, *last = NULL;
void append(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
    }
    else
    {
        last->next = temp;
        temp->previous = last;
        last = temp;
    }
}
int size()
{
    struct node *current = head;
    int count = 0;
    while (current)
    {
        count++;
        current = current->next;
    }
    return count;
}
void traverse()
{
    struct node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
void reverse_traverse()
{
    struct node *current = last;
    while (current)
    {
        cout << current->data << " ";
        current = current->previous;
    }
}
void insert(int position, int value)
{
    struct node *temp = new node, *current = head;
    temp->data = value;
    temp->next = NULL;
    temp->previous = NULL;
    int temp_pos = position;
    if (position <= size())
    {
        if (position == 0)
        {
            temp->next = current;
            current->previous = temp;
            head = temp;
        }
        else
        {
            if (position == size())
            {
                last->next = temp;
                temp->previous = last;
                last = temp;
                return;
            }

            while (--position)
            {
                current = current->next;
            }
            temp->next = current->next;
            current->next->previous = temp; //this statement should be taken care of because when the current->next is null then there would be no previous to the null so while inserting at last we should take care of this
            current->next = temp;
            temp->previous = current;
        }
    }
}
void erase(int position)
{
    struct node *current = head;
    if (position < size())
    {
        if (position == 0)
        {
            head = current->next;
            current->next = NULL;
            head->previous = NULL;
            delete current;
        }
        else
        {
            while (position--)
            {
                current = current->next;
            }
            current->previous->next = current->next;
            if (current->next)
                current->next->previous = current->previous;
            else
                last = current->previous;
            current->next = NULL;
            current->previous = NULL;
            delete current;
        }
    }
}
void reverse()
{
    struct node *current = head;
    while (current)
    {
        struct node *temp = current->next;
        current->next = current->previous;
        current->previous = temp;
        current = current->previous;
        if (current->next == NULL)
        {
            last = head;
            head = current;
        }
    } 
}
int main()

{
    cout << "before reversing" << endl;
    append(2);
    append(3);
    append(5);
    append(343);
    append(232);
    // append(2323);
    // insert(5, 23232);
    // erase(4);
    append(4566);
    // erase(2);
    traverse();
   
    // reverse_traverse();
    return 0;
} 