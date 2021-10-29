// given a complete binary tree we should calcualte the no of nodes in binary tree less than O(N) time
// Note : The tree should be complete binary tree
// if h is the height of the full binary tree then no of nodes in tree is 2^h -1
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
    int leftheight(Node *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->left;
        }
        return height;
    }
    int rightheight(Node *root)
    {
        int height = 0;
        while (root)
        {
            height++;
            root = root->right;
        }
        return height;
    }
    int countnodes(Node *root)
    {
        if (!root)
            return 0;
        int lh = leftheight(root);
        int rh = rightheight(root);
        if (lh == rh)
            return (1 << lh) - 1;
        return 1 + countnodes(root->left) + countnodes(root->right);
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    cout << tree.countnodes(root) << endl;
}