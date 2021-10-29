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
    // given a binary tree we should say whether the tree is symmetrical about the root node or not.
    // that mean mirror image of left subtree should be identical to the right subtree
    // we traverse the right and left subtrees simultaneously, we start from the root->left and root->right and the left node data in the left subtree should be equal to the right node data in the right sub tree
    // and the right node data in left subtree should be equal to the left node data in the right subtree

    // i.e temp1->left->data == temp2->right->data;
    // temp1->right->data = temp2->left->data

    // see strivers playlist for better understanding
    bool symmetrical(Node *temp1, Node *temp2)
    {
        if (!temp1 or !temp2)
            return temp1 == temp2;
        if (temp1->data != temp2->data)
            return false;
        return symmetrical(temp1->left, temp2->right) && symmetrical(temp1->right, temp2->left);
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    tree.symmetrical(root->left,root->right) ? (cout << "symmetrical") : (cout << "Unsymmetrical");
    return 0;
} 