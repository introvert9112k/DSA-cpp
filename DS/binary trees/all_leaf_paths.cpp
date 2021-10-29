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
    // This will calculate the all the leafnodes paths
    void leafpaths(Node *temp, vector<vector<int>> &ans, vector<int> &arr)
    {
        if (!temp)
            return;
        arr.push_back(temp->data);
        leafpaths(temp->left, ans, arr);
        leafpaths(temp->right, ans, arr);
        if (!temp->left and !temp->right)
            ans.push_back(dup);

        arr.pop_back();
    }
    // https://www.geeksforgeeks.org/given-a-binary-tree-print-all-root-to-leaf-paths/
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<vector<int>> ans;
    vector<int> arr;
    tree.leafpaths(root, ans, arr);
    for (auto vec : ans)
    {
        for (auto x : vec)
            cout << x << " ";
        cout << endl;
    }
}