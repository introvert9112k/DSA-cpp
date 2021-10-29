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
    bool root_to_node(vector<int> &ans, Node *temp, int x)
    {
        if (!temp)
            return false;
        ans.push_back(temp->data);
        if (temp->data == x)
            return true;
        if (root_to_node(ans, temp->left, x))
            return true;
        if (root_to_node(ans, temp->right, x))
            return true;
        ans.pop_back();
        return false;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<int> ans;
    int x;
    cout << "Enter the data of the node" << endl;
    cin >> x;
    tree.root_to_node(ans, root, x);
    for (auto x : ans)
        cout << x << " ";
} 