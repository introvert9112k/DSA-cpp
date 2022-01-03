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
    node() {}
};
node *create()
{
    int x;
    cout << "Enter the data" << endl;
    cin >> x;
    if (x == -1)
        return NULL;
    node *new_node = new node(x);
    cout << "Enter the left child of the node  " << new_node->data << endl;
    new_node->left = create();
    cout << "Enter the right child of the node  " << new_node->data << endl;
    new_node->right = create();
    return new_node;
}
void preorder(node *temp)
{
    if (!temp)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
// one variation in iterative_preoder
void iterative_preorder(node *root)
{
    stack<node *> stack;
    stack.push(root);
    while (!stack.empty())
    {
        node *temp = stack.top();
        cout << temp->data << " ";
        stack.pop();
        if (temp->right)
            stack.push(temp->right);
        if (temp->left)
            stack.push(temp->left);
    }
}
void iterative_preorder1(node *temp)
{
    stack<node *> stack;
    while (temp != NULL or !stack.empty())
    {
        while (temp != NULL)
        {
            cout << temp->data << " ";
            stack.push(temp);
            temp = temp->left;
        }
        temp = stack.top();
        stack.pop();
        temp = temp->right;
    }
} 
int main()

{

    node *root = create();
    cout << "recursive preorder traversal is " << endl;
    preorder(root);
    cout << endl;
    cout << "Iterative preorder traversal is " << endl;
    iterative_preorder1(root);

    return 0;
}