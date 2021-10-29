// problem statement
// given a binary tree we should say whether the tree follows the max-heap property or not

// ---------------- Min and max heap--------------------------------
// A binary heap is a complete binary tree which satisfies the heap ordering property. The ordering can be one of two types:

// the min-heap property: the value of each node is greater than or equal to the value of its parent, with the minimum-value element at the root.
// the max-heap property: the value of each node is less than or equal to the value of its parent, with the maximum-value element at the root.

// ----complete binary tree -------------------------
// we know that the binary heap(either max heap or min heap ) is a complete binary tree .
// A complete binary tree is a binary tree in which every level, except possibly the last, is completely filled, and all nodes are as far left as possible

// Approach
// first we should simulatenously see whether the tree is complete binary tree and following the max- heap property
// For a given Node there are four possiblites
// Both left and right child exists
// Left exist and right does not exists
// Right exists and right don't
// Both right and right child don't exists

// we traverse the tree in level order and check for these conditions

// 1.both left and right exists
// then we should check whether any of the childs data is greater than the node data,if yes it violates the max-heap property so return false

// 2.left don't and right does
// If there is a node which don't have left child and has right child,it violates the complete binary treee so return false

// 3.left does and right don't
// This only possible when the node height is equal to 1 less than the height of tree, if this does not satisfy return false, If it satisfies if child data > node data return false

// 4.both left and right child don't exists
// // This is only possible for leaf node,if this cases encounters check of height of the node if it is not equal to the height of the tree return false

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
    int height(Node *temp)
    {
        if (!temp)
            return 0;
        return max(height(temp->left), height(temp->right)) + 1;
    }
    bool isHeap(Node *root, int h)
    {
        deque<Node *> deque;
        deque.push_back(root);
        int level = 0;
        while (!deque.empty())
        {
            int size = deque.size();
            level++; // for keep tracking level
            for (int i = 0; i < size; i++)
            {
                Node *temp = deque.front();
                deque.pop_front();
                // -----------1st condition----------
                if (temp->left and temp->right)
                {
                    if ((temp->left->data > temp->data) or (temp->right->data > temp->data))
                        return false;
                    deque.push_back(temp->left);
                    deque.push_back(temp->right);
                }
                // ------------2nd condition-------------
                else if (!temp->left and temp->right)
                    return false;
                // ----------3rd condition-----------
                else if (temp->left and !temp->right)
                {
                    if (level != h - 1 or temp->left->data > temp->data)
                        return false;
                    deque.push_back(temp->left);
                }
                // ---------4th condition---------
                else
                {
                    if (level != h)
                        return false;
                }
            }
        }
        return true;
    }
    // done in geekforgeeks
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int h = tree.height(root);
    tree.isHeap(root, h) ? cout << "Yes" << endl : cout << "NO" << endl;
}
