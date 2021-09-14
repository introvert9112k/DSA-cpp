#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    node *next;
};
node *detectloop(node *head)
{
    // flored's loop detection algorthim is used to detect loop in linkedlist
    // slow and fast pointer technique is used to detect loop in linkedlist, if we want to find the starting point of the linkedlist,set the slow pointer to head ,and fast is pointing to the location where the previously fast and slow met, now move the slow and fast pointer one step, the node at which there values becomes equal is the starting node of the loop

    // this function will return the node where fast and slow pointers met, if there is a loop else returns NULL
    node *slow = head, *fast = head;
    while (fast and fast->next)
    {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast)
            return slow;
    }
    return NULL;
}
void removeloop(node *head)
{
    node *fast = detectloop(head);
    if (fast) //if loop is present
    {
        // finding the starting point of the loop
        node *slow = head; //reseting the slow pointer to the first node
        while (slow != fast)
        {
            slow = slow->next;
            fast = fast->next;
        }
        // now the slow and fast both pointing to the starting loop node in linked list
        // now we should remove the loop from the linked list
        // now start from the loop starting node,and check for node whose next is the loop starting node,and breaks the loop by making next of this node to null

        node *temp = slow; //starting from the loop start node,whenever we again reach this node,the before node is the last node in loop
        while (temp->next != slow)
        {
            temp = temp->next;
        }
        // now we found the node,whose next node is slow
        // so let's make this node next to null, inorder to break the node
        temp->next = NULL;
    }
} 
int main()

{

    return 0;
}