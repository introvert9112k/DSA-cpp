// problem statement 
// concatenate the two linked list 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head1 = NULL, *last1 = NULL;
struct node *head2 = NULL, *last2 = NULL;

void append(struct node* &head,struct node* &last,int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if(head==NULL)
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

void traverse(struct node*temp)
{
    
    while(temp)
    {
        cout << temp->data << " ";
        temp = temp->next;
    }
} 

void concatenate()
{
    last1->next = head2;
} 
int main() 

{

    append(head1, last1, 12);
    append(head1, last1, 232);
    append(head1, last1, 3434);
    append(head2, last2, 323);
    append(head2, last2, 534);
    concatenate();
    traverse(head1); 

    return 0;

} 