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
    // For a given node,this will find out the path from root node to that node
    bool Nodepath(Node *temp, vector<int> &arr, int tar)
    {
        if (!temp)
            return false;
        arr.push_back(temp->data);
        if (temp->data == tar)
            return true;
        if (Nodepath(temp->left, arr, tar) or Nodepath(temp->right, arr, tar))
            return true;
        arr.pop_back();
        return false;
    }

    // strivers playlist
    // article
    // https://www.geeksforgeeks.org/print-path-root-given-node-binary-tree/
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<int> arr;
    int target;
    cout << "enter target" << endl;
    cin >> target;
    tree.Nodepath(root, arr, target);
    if (arr.empty())
        cout << "target is not present in tree" << endl;
    for (auto val : arr)
        cout << val << " ";
} 