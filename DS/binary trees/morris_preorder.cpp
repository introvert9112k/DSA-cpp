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
    void preorder(Node *root)
    {
        if (root == NULL)
            return;
        cout << root->data << " ";
        preorder(root->left);
        preorder(root->right);
    }
    void morrispreorder(Node *root)
    {
        Node *curr = root;
        while (curr != NULL)
        {
            if (curr->left == NULL)
            {
                cout << curr->data << " ";
                curr = curr->right;
            }
            else
            {
                Node *prev = curr->left;
                while (prev->right and prev->right != curr)
                    prev = prev->right;
                if (prev->right == NULL)
                {
                    prev->right = curr;
                    cout << curr->data << " ";
                    curr = curr->left;
                }
                if (prev->right == curr)
                {
                    prev->right = NULL;
                    curr = curr->right;
                }
            }
        }
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    cout << "morris preorder traversal is : " << endl;
    tree.morrispreorder(root);
    cout << endl;
    cout << "preorder traversal is : " << endl;
    tree.preorder(root);
} 