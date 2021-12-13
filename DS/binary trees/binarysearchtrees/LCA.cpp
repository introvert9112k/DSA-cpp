// problem statement
// Find the least common ancestor of two nodes in bst

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
    Node *lca(Node *curr, int n, int m)
    {
        while (curr)
        {
            if (curr->data == n or curr->data == m)
                return curr;
            else if (n < curr->data and m < curr->data)
                curr = curr->left;
            else if (n > curr->data and m > curr->data)
                curr = curr->right;
            else
                return curr;
        }
        return NULL;
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
    cout << "enter the two values" << endl;
    int n, m;
    cin >> n >> m;
    Node *res = tree.lca(root, n, m);
    cout << (res ? res->data : -1) << endl;
} 