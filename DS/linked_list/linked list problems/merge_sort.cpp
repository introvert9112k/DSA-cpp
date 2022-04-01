#include <bits/stdc++.h>
using namespace std;

class ListNode
{
public:
    int val;
    ListNode *next;
    ListNode(int x)
    {
        val = x;
        next = nullptr;
    }
};
ListNode *head = nullptr, *tail = nullptr;
void InsertatLast(int val)
{
    if (head == nullptr)
        head = new ListNode(val), tail = head;
    else
        tail->next = new ListNode(val), tail = tail->next;
}
void PrintList(ListNode *curr)
{
    for (; curr != nullptr; curr = curr->next)
        cout << curr->val << " ";
    cout << endl;
}
// Gives the middle node and node next to middle node
pair<ListNode *, ListNode *> MiddleNode(ListNode *temphead, ListNode *temptail)
{
    ListNode *slow = temphead, *fast = temphead;
    while (fast != temptail && fast->next != temptail)
        slow = slow->next, fast = fast->next->next;
    ListNode *nextnode = slow->next;
    slow->next = nullptr;
    return {slow, nextnode};
}
// Merges the two sorted lists
ListNode *MergeTwoLists(ListNode *head1, ListNode *head2)
{
    ListNode *dummyHead = new ListNode(0), *dummytail = dummyHead;
    while (head1 && head2)
    {
        if (head1->val <= head2->val)
        {
            dummytail->next = head1;
            dummytail = head1;
            head1 = head1->next;
        }
        else
        {
            dummytail->next = head2;
            dummytail = head2;
            head2 = head2->next;
        }
    }
    head1 ? dummytail->next = head1 : dummytail->next = head2;
    return dummyHead->next;
} 
// Driving code
ListNode *Mergesort(ListNode *temphead, ListNode *temptail)
{
    if (temphead == temptail)
        return temphead;
    pair<ListNode *, ListNode *> temp = MiddleNode(temphead, temptail);
    ListNode *mid = temp.first, *nextnode = temp.second;
    ListNode *head1 = Mergesort(temphead, mid);
    ListNode *head2 = Mergesort(nextnode, temptail);
    return MergeTwoLists(head1, head2);
}

int main()

{

    InsertatLast(-1);
    InsertatLast(9);
    InsertatLast(2);
    InsertatLast(188);
    InsertatLast(-3);
    cout << "Linked List before appllying mergesort is " << endl;
    PrintList(head);
    cout << "Linked List after applying mergesort is " << endl;
    PrintList(Mergesort(head, nullptr));
    return 0;
} 