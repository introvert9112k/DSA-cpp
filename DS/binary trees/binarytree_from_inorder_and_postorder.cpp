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
    Node *treeconstruct(vector<int> &in, int inst, int inend, vector<int> &po, int post, int poend, unordered_map<int, int> &inmap)
    {
        if (post > poend or inst > inend)
            return NULL;
        Node *root = new Node(po[poend]);
        int inroot = inmap[poend];
        int numsleft = inroot - inst;
        root->left = treeconstruct(in, inst, inroot - 1, po, post, post + numsleft - 1, inmap);
        root->right = treeconstruct(in, inroot + 1, inend, po, post + numsleft, poend - 1, inmap);
        return root;
    }
    void preorder(Node *curr)
    {
        if (!curr)
            return;
        cout << curr->data << " ";
        preorder(curr->left);
        preorder(curr->right);
    }
};

int main()
{
    binarytree tree;
    int n;
    cout << "enter the number of nodes in tree " << endl;
    cin >> n;
    vector<int> in(n), po(n);
    cout << "enter the inorder traversal of the binary tree " << endl;
    unordered_map<int, int> inmap;
    for (int i = 0; i < n; i++)
    {
        cin >> in[i];
        inmap[in[i]] = i;
    }
    cout << "enter the postorder traversal of the tree  " << endl;
    for (int i = 0; i < n; i++)
        cin >> po[i];
    Node *root = tree.treeconstruct(in, 0, n - 1, po, 0, n - 1, inmap);
    cout << root->data << endl;
    cout << "preorder traversal of the tree is : " << endl;
    tree.preorder(root);
}    