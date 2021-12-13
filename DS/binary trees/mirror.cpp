// problem statement
// given a tree,we should convert the given tree into its mirror image

// ------Approach-----
// Use any traversal and swap left and right nodes

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
    void mirror(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        Node *left, *right;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            left = right = NULL;
            if (curr->left)
            {
                q.push(curr->left);
                left = curr->left;
            }
            if (curr->right)
            {
                q.push(curr->right);
                right = curr->right;
            }
            curr->left = right;
            curr->right = left;
        }
    }
    Node *mirror1(Node *root)
    {
        if (!root)
            return NULL;
        Node *left = mirror1(root->left);
        Node *right = mirror1(root->right);
        root->left = right;
        root->right = left;
        return root;
    }
    void inorder(Node *root)
    {
        if (!root)
            return;
        inorder(root->left);
        cout << root->data << " ";
        inorder(root->right);
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    tree.mirror1(root);
    tree.inorder(root);
}