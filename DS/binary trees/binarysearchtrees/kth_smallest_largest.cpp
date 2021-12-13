// problem statement
// given an binary search tree find the kth smallest and largest node
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
    void kthsmallest(Node *curr, int &cnt, int k, int &val)
    {
        if (!curr)
            return;
        kthsmallest(curr->left, cnt, k, val);
        cnt++;
        if (cnt == k)
            val = curr->data;
        kthsmallest(curr->right, cnt, k, val);
    }
    void inorder(Node *curr)
    {
        if (!curr)
            return;
        inorder(curr->left);
        cout << curr->data << " ";
        inorder(curr->right);
    }
    // kth largest element is n-k th smallest element from 1st
    void kthlargest(Node *curr, int &cnt, int k, int &val, int n)
    {
        if (!curr)
            return;
        kthlargest(curr->left, cnt, k, val, n);
        if (cnt == (n - k))
            val = curr->data;
        cnt++;
        kthlargest(curr->right, cnt, k, val, n);
    } 
    int countnodes(Node *curr)
    {
        if (!curr)
            return 0;
        return countnodes(curr->left) + countnodes(curr->right) + 1;
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
    int k;
    cout << "Enter the value of k" << endl;
    cin >> k;
    int cnt = 0;
    tree.inorder(root);
    cout << endl;
    tree.kthsmallest(root, cnt, k, val);
    cout << "the kth smallest element in the tree is " << val << endl;
    cnt = 0;
    int n = tree.countnodes(root);
    tree.kthlargest(root, cnt, k, val, n);
    cout << "the kth largest element in tree is: " << val << endl;
} 