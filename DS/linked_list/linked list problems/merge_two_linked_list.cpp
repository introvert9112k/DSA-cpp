#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL, *last1 = NULL;
struct node *head2 = NULL, *last2 = NULL;
struct node *merge_head = NULL, *merge_last = NULL;

void append(struct node *&head, struct node *&last, int value)
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
void traverse(struct node *head)
{
    struct node *current = head;
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
void merge()
{
    struct node *temp1 = head1, *temp2 = head2;
    while (temp1 != NULL && temp2 != NULL)
    {
        if (temp1->data < temp2->data)
        {
            append(merge_head, merge_last, temp1->data);
            temp1 = temp1->next;
        }
        else if (temp2->data < temp1->data)
        {
            append(merge_head, merge_last, temp2->data);
            temp2 = temp2->next;
        }
        else
        {
            append(merge_head, merge_last, temp1->data);
            temp1 = temp1->next;
            temp2 = temp2->next;
        }
    }
    if (temp1 == NULL)
    {
        while (temp2)
        {
            append(merge_head, merge_last, temp2->data);
            temp2 = temp2->next;
        }
    }
    else
    {
        while (temp1)
        {
            append(merge_head, merge_last, temp1->data);
            temp1 = temp1->next;
        }
    }
}
// in merge1 we create extra linked list and copied the values of two linked list in sorted order
void merge2()
{
    struct node *temp2 = NULL, *temp1 = head1;
    struct node *temp4 = NULL, *temp3 = head2;
    // cout<< "saisri angajala" <<endl;
    while (temp1 != NULL && temp3 != NULL)
    {
        if (temp1->data <= temp3->data)
        {
            if (temp1->data == temp3->data)
                temp3 = temp3->next;
            temp2 = temp1;
            temp1 = temp1->next;
        }
        else
        {
            temp4 = temp3;
            temp3 = temp3->next;
            temp4->next = temp1;
            if (temp2 == NULL) 
                head1 = temp4;
            else
                temp2->next = temp4;
            temp2 = temp4;
        }
    } 
    if (temp1 == NULL)
    {
        struct node *temp5 = NULL;
        while (temp3)
        {
            temp2->next = temp3;
            temp3 = temp3->next;
        } 
    } 
    // here we did not create a new linked list we merged the linked list 2 into linked list 1 
} 

int main()

{

    append(head1, last1, 23);
    append(head1, last1, 34);
    append(head1, last1, 231);
    append(head1, last1, 543);
    append(head2, last2, 3);
    append(head2, last2, 34);
    append(head2, last2, 36);
    append(head2, last2, 343);
    append(head2, last2, 2232);
    merge2();
    traverse(head1);

    return 0;
}  