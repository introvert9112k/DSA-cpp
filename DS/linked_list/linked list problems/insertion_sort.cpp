// problem statement
// Given a linked list sort the linked list using insertion sort
#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int data;
    ListNode *next;
    ListNode(int x)
    {
        data = x,
        next = nullptr;
    }
};

ListNode *head = nullptr, *tail = nullptr;
void InsertatLast(int val)
{
    ListNode *temp = new ListNode(val);
    if (head == nullptr)
        head = temp, tail = temp;
    else
        tail->next = temp, tail = temp;
}
void PrintList(ListNode* head_ref)
{
    ListNode *curr = head_ref;
    for (; curr != nullptr; curr = curr->next)
        cout << curr->data << " ";
    cout << endl;
}

ListNode *sortedListhead = nullptr; 
//Ascending order sorting
void sortAscending(ListNode *newnode)
{
    if (sortedListhead == nullptr || sortedListhead->data >= newnode->data)
        newnode->next = sortedListhead, sortedListhead = newnode;
    else 
    {
        ListNode *curr = sortedListhead;
        while(curr->next && curr->next->data < newnode->data)
            curr = curr->next;
        newnode->next = curr->next;
        curr->next = newnode;
    }
}  

// sorting in descending order
void sortDescending(ListNode* newnode)
{
    if(sortedListhead == nullptr || sortedListhead->data <= newnode->data)
        newnode->next = sortedListhead, sortedListhead = newnode;
    else
    {
        ListNode *curr = sortedListhead;
        while(curr->next && curr->next->data > newnode->data)
            curr = curr->next;
        newnode->next = curr->next;
        curr->next = newnode;
    }
} 
void Insertionsort()
{
    ListNode *curr = head;
    while (curr)
    {
        ListNode *nextnode = curr->next;
        sortDescending(curr);
        curr = nextnode;
    }
} 

// Time Complexity --- O(n*n)
// Space complexity --- O(1)

int main()

{
    InsertatLast(3);
    InsertatLast(4);
    InsertatLast(5);
    InsertatLast(1);
    InsertatLast(2);
    cout << "Linked List before sorting" << endl;
    PrintList(head);
    Insertionsort();
    cout << "LinkedList after sorting in Ascending order" << endl;
    PrintList(sortedListhead);
    return 0;
}  