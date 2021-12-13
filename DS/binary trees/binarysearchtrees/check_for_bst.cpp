#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};

class binarytree
{
public:
    Node *construct()
    {
        int x;
        cout << "Enter the data" << endl;
        cin >> x;
        if (x == -1)
            return NULL;
        Node *new_node = new Node(x);
        cout << "Enter the left child of the node " << new_node->data << endl;
        new_node->left = construct();
        cout << "Enter the right child of the node " << new_node->data << endl;
        new_node->right = construct();
        return new_node;
    }
    bool isbst(Node *curr, int minval, int maxval)
    {
        if (!curr)
            return true;
        if (curr->data < minval or curr->data > maxval)
            return false;
        return isbst(curr->left, minval, curr->data) and isbst(curr->right, curr->data, maxval);
    }
    // strivers playlist
    // for
    // every node we assign the range in which it's value could lie,for intial or root nodes the range is -int_min to int_max
    // upon going left the range for next node becomes {int_min,curr->data} for right range will be {curr->data,int_max}
    // in any case if the curr->data is out of this range then it is not bst
};
 
int main()
{
    binarytree tree;
    Node *root = tree.construct();
    cout << (tree.isbst(root, INT_MIN, INT_MAX) ? "isbst" : "not bst") << endl;
}