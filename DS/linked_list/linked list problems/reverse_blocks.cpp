#include <iostream>
#include <string>
#include <algorithm>
#include<vector>

using namespace std;

struct node
{
    int data;
    struct node *next;
};
struct node *head = NULL, *last = NULL;
void append(int value)
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
int size()
{
    struct node *temp = head;
    int count = 0;
    while (temp)
    {
        count++;
        temp = temp->next;
    }
    return count;
}
void traverse(struct node *current = head)
{
    while (current)
    {
        cout << current->data << " ";
        current = current->next;
    }
}
void reverse_block(int *array, int n)
{
    int length = size();
    vector<int> v;
    struct node *temp = head;
    for (int i = 0; i < n; i++)
    {
        length = length - array[i];
        if(length >= 0)
        {
            struct node *temp2 = temp;
            int len = array[i];
            while (len--) 
            {
                v.push_back(temp->data);
                temp = temp->next;
            }
            for (int j = array[i] - 1; j >= 0; j--)
            {
                temp2->data = v[j];
                temp2 = temp2->next;
            }
            v.clear();
        }   
        else 
        {
            struct node *temp3 = temp;
            while (temp)
            {
                v.push_back(temp->data);
                temp = temp->next;
           } 
           for (int i = v.size() - 1; i >= 0; i--)
           {
               temp3->data = v[i];
               temp3 = temp3->next;
           } 
        } 

    }  
}    
int main() 

{

    int x;
    cin >> x;
    while (x != -1)
    {
        append(x);
        cin >> x;
    } 
    int n; 
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];
    reverse_block(array,n); 
    traverse();
    return 0;
} 
