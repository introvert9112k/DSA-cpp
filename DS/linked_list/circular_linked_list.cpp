// in this we will look at the circular linked list
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL,*last =NULL;

void append(int value)
{
    struct node *temp = new node;
    temp->data = value;
    temp->next = NULL;
    if(head == NULL)
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
    }while (current!= head);
    
} 
void recursive_traverse(struct node*current = head) 
{
    static int flag = 0;
    if(current!=head or flag==0)
    {
        flag = 1;
        cout << current->data << " ";
        current = current->next;
        recursive_traverse(current);
    } 
}
int main() 

{

    append(23);
    append(34);
    append(45);
    recursive_traverse();


    return 0;

}  