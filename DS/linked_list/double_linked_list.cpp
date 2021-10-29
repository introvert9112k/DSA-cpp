// in this we will look at the double linked list
#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    Node *prev, *next;
    int data;
    Node(int x)
    {
        data = x;
        prev = NULL;
        next = NULL;
    }
};

class doublelist
{
public:
    Node *head = NULL, *tail = NULL;
    void append(int value)
    {
        Node *temp = new Node(value);
        if (!head)
        {
            head = temp;
            tail = temp;
        }
        else
        {
            tail->next = temp;
            temp->prev = tail;
            tail = tail->next;
        }
    }
    int size()
    {
        Node *temp = head;
        int cnt = 0;
        while (temp)
        {
            temp = temp->next;
            cnt++;
        }
        return cnt;
    }
    void traverse()
    {
        Node *curr = head;
        while (curr)
        {
            cout << curr->data << " ";
            curr = curr->next;
        }
    }

    void insert(int pos, int val)
    {
        if (pos < size())
        {
            Node *temp = new Node(val);
            if (pos == 1)
            {
                temp->next = head;
                head->prev = temp;
                head = temp;
                return;
            }
            Node *previous, *curr = head;
            while (--pos)
            {
                previous = curr;
                curr = curr->next;
            }
            previous->next = temp;
            temp->prev = previous;
            temp->next = curr;
            curr->prev = temp;
        }
    }
    void reverse()
    {
        Node *curr = head, *temp;
        while (curr)
        {
            temp = curr->prev;
            curr->prev = curr->next;
            curr->next = temp;
            curr = curr->prev;
        }
        if (temp != NULL)
            head = temp->prev;
    }
    void remove(int pos)
    {
        int n = size();
        if (pos <= n)
        {
            if (pos == 1)
            {
                Node *temp = head;
                head = head->next;
                temp->next = NULL;
                if (n > 1)
                    head->prev = NULL;
                delete temp;
            }
            else if (pos == n)
            {
                Node *temp = tail;
                tail = tail->prev;
                temp->prev = NULL;
                tail->next = NULL;
                delete temp;
            }
            else
            {
                Node *previous, *curr = head;
                while (--pos)
                {
                    previous = curr;
                    curr = curr->next;
                }
                previous->next = curr->next;
                curr->next->prev = previous;
                delete curr;
            }
        }
    }
};

int main()

{
    doublelist dl;
    dl.append(1);
    dl.append(2);
    dl.append(3);
    dl.append(10);
    dl.append(343);
    dl.reverse();
    dl.traverse();
    return 0;
} 