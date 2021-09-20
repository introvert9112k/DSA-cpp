#include <bits/stdc++.h>
using namespace std;
struct node
{

    int data;
    node *prev;
    node(int x)
    {
        this->data = x;
        this->prev = NULL;
    }
};
// factorial of the larger number
// reference:https://www.youtube.com/watch?v=VCfZOe1oJHU&ab_channel=DhruvGoyal
node *tail = new node(1);
node *head = tail;

// using linked list
void multiply(int n)
{
    node *curr = tail, *prevnode = tail;
    int ans, carry = 0;
    while (curr)
    {
        ans = curr->data * n + carry;
        curr->data = ans % 10;
        carry = ans / 10;
        prevnode = curr;
        curr = prevnode->prev;
    }
    while (carry != 0)
    {
        node *temp = new node(carry % 10);
        prevnode->prev = temp;
        carry = carry / 10;
        prevnode = prevnode->prev;
    }
}
// printing function for linkedlist
void print()
{
    node *first = tail, *second = NULL, *third = NULL;
    while (first)
    {
        third = second;
        second = first;
        first = first->prev;
        second->prev = third;
    }
    node *temp = second;
    while (temp)
    {
        cout << temp->data;
        temp = temp->prev;
    }
}
// using vector
vector<int> factorial(1, 1);
void multiply1(int x)
{
    int ans, carry = 0;
    int i = 0, n = factorial.size();
    while (i != n)
    {
        ans = factorial[i] * x + carry;
        factorial[i] = ans % 10;
        carry = ans / 10;
        i++;
    } 
    while(carry!=0)
    {
        factorial.push_back(carry % 10);
        carry = carry / 10;
    }
} 
// printing function for vector
void print1()
{
    reverse(factorial.begin(), factorial.end());
    for(auto x: factorial)
        cout << x;
}
int main()

{

    int n;
    cin >> n;
    for (int i = 2; i <= n; i++)
    {
        multiply(i);
        multiply1(i);
    }
    print();
    cout << endl;
    print1();

    return 0;
} 