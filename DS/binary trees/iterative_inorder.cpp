#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
node *root = NULL;
node *construct()
{
    int x;
    cout << "Enter the data" << endl;
    cin >> x;
    if (x == -1)
        return NULL;
    node *curr = new node(x);
    cout << "Enter the left child of the node " << curr->data << endl;
    curr->left = construct();
    cout << "Enter the right child of the node " << curr->data << endl;
    curr->right = construct();
    return curr;
}
void inorder(node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void iterative_inorder(node *temp)
{
    stack<node *> stack;
    while (temp != NULL or !stack.empty())
    {
        while (temp != NULL)
        {
            stack.push(temp);
            temp = temp->left;
        }
        temp = stack.top();
        cout << temp->data;
        stack.pop();
        temp = temp->right;
    }
} 
int main()
{
    root = construct();
    cout << "recursive inorder traversal of the tree is " << endl;
    inorder(root);
}
