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
    // rightview of the tree is the nodes that will appear if we see from the right side of the tree
    // In level order traversal the last node in each level give the right view of the binary tree
    // we can do it using recursion too
    // In recursion space complexity will be less when compared to the level order traversal
    // here we are using the reverse preorder traversal i.e root,right,left

    void rightview(vector<int> &ans, Node *temp, int level)
    {
        if (!temp)
            return;
        if (level == ans.size())
            ans.push_back(temp->data);
        rightview(ans, root->right, level + 1);
        rightview(ans, root->left, level + 1);
    }

    // In level order traversal the first node in each level give the left view of the binary tree
    void leftview(vector<int> &ans, Node *temp, int level)
    {
        if (!temp)
            return;
        if (level == ans.size())
            ans.push_back(temp->data);
        leftview(ans, root->left, level + 1);
        leftview(ans, root->right, level + 1);
    }

    // striver's playlist
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<int> ans = tree.rightview();
}