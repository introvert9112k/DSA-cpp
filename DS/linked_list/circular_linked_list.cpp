// in this we will look at the circular linked list
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

int size(struct node *current = head)
{
    int count = 0;
    if (current == NULL)
        return 0;
    else
    {

        do
        {
            count++;
            current = current->next;
        } while (current != head);
    }
    return count;
}

void append(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if (head == NULL)
    {
        head = temp;
        last = temp;
        temp->next = head;
    }
    else
    {
        last->next = temp;
        temp->next = head;
        last = temp;
    }
}
void traverse()
{
    struct node *current = head;
    do
    {
        cout << current->data << " ";
        current = current->next;
    } while (current != head);
}
void recursive_traverse(struct node *current = head)
{
    static int flag = 0;
    if (current != head or flag == 0)
    {
        flag = 1;
        cout << current->data << " ";
        current = current->next;
        recursive_traverse(current);
    }
}
void insert(int position, int value)
{
    struct node *temp = new node, *current = head, *previous = NULL;
    temp->data = value;
    temp->next = NULL;
    if (position <= size())
    {

        if (position == 0)
        {
            temp->next = current;
            head = temp;
            last->next = head;
        }
        else
        {
            if (position == size())
            {
                last->next = temp;
                temp->next = head;
                last = temp;
                return;
            }
            else
            {

                while (position--)
                {
                    previous = current;
                    current = current->next;
                }
                temp->next = current;
                previous->next = temp;
            }
        }
    }
}
void erase(int position)
{
    struct node *current = head, *previous = NULL;
    int length = size() - 1;
    int temp_pos = position;
    if (position <= length)
    {
        if (position == 0)
        {
            head = current->next;
            current->next = NULL;
            delete current;
            last->next = head;
        }
        else
        {

            while (position--)
            {
                previous = current;
                current = current->next;
            }
            if (temp_pos == length)
            {
                previous->next = head;
                delete current;
                last = previous;
            }
            else
            {

                previous->next = current->next;
                current->next = NULL;
                delete current;
            }
        }
    }
}
int main()

{

    append(23);
    append(34);
    append(45);
    // recursive_traverse();
    // insert(4, 3434);
    // erase(0);
    append(23);
    // erase(2);
    erase(0);
    erase(2);
    append(46);
    append(78);
    insert(2, 4546);
    // erase(1);
    erase(1);
    erase(2);
    erase(2);
    erase(1);
    append(456);
    insert(2, 454664);
    erase(0);
    traverse();

    return 0;
} 