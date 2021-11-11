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
Node *root = NULL;
class binarysearchtree
{
public:
    void insert(int x)
    {
        if (!root)
        {
            root = new Node(x);
            return;
        }
        Node *curr = root;
        while (curr)
        {
            if (x < curr->data)
            {
                if (curr->left)
                    curr = curr->left;
                else
                {
                    curr->left = new Node(x);
                    break;
                }
            }
            else
            {
                if (curr->right)
                    curr = curr->right;
                else
                {
                    curr->right = new Node(x);
                    break;
                }
            }
        }
    }
    void inorder(Node *curr = root)
    {
        if (!curr)
            return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
    Node *search(int val, Node *curr = root)
    {
        // this will stop when curr is null or when the node with given value is found
        while (curr != NULL and curr->data != val)
            val < curr->data ? curr = curr->left : curr = curr->right;
        // if val < curr->data then check in left subtree else check in right subtree
        return curr;
    }
};
int main()
{
    binarysearchtree tree;
    cout << "enter the nodes in binary search tree" << endl;
    int x;
    cin >> x;
    while (x != -1)
    {
        tree.insert(x);
        cin >> x;
    }
    int val;
    cout << "enter the value to search in bst" << endl;
    cin >> val;
    tree.search(val) ? cout << "present" : cout << "absent";
}