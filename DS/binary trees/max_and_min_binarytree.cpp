#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
}; 
class binarytree
{
public:
    node *create()
    {
        node *new_node;
        int x;
        cout << "Enter the data" << endl;
        cin >> x;
        if (x == -1)
            return NULL;
        new_node = new node(x);
        cout << "Enter the left child of the node  " << new_node->data << endl;
        new_node->left = create();
        cout << "Enter the right child of the node " << new_node->data << endl;
        new_node->right = create();
        return new_node;
    } 
    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
}; 
int maximum(node *temp)
{
    int maxval;
    if (!temp)
        return INT_MIN;
    // lmax is maximum value in left subtreee
    int lmax = maximum(temp->left);
    // rmax is maximum value in right subtree
    int rmax = maximum(temp->right);
    // global maximum is maximum of left ,right subtree and current node data
    maxval = max({lmax, rmax, temp->data});
    return maxval;
} 
int minimum(node *temp)
{
    int minval;
    if (!temp)
        return INT_MAX;
    int lmin = minimum(temp->left);
    int rmin = minimum(temp->right);
    minval = min({lmin, rmin, temp->data});
    return minval;
} 
int main()

{
    binarytree tree;
    node *root = tree.create();
    tree.preorder(root);
    cout << endl;
    cout << "maximum value in binary tree is : " << maximum(root) << endl;
    cout << "minimum value in binary tree is : " << minimum(root) << endl;
    return 0;
} 