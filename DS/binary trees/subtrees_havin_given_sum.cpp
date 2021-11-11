#include <bits/stdc++.h>
using namespace std;
// problem statement
// Given a binary tree and an integer X. Your task is to complete the function countSubtreesWithSumX() that returns the count of the number of subtress having total node’s data sum equal to the value X.
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
    int countSubtreewithsumx(Node *root, int &ans, int x)
    {
        if (!root)
            return 0;
        int lsum = countSubtreewithsumx(root->left, ans, x);
        int rsum = countSubtreewithsumx(root->right, ans, x);
        if ((lsum + rsum + root->data) == x)
            ans++;
        return lsum + rsum + root->data;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int x, ans = 0;
    cout << "enter the value of x" << endl;
    cin >> x;
    tree.countSubtreewithsumx(root, ans, x);
    cout << "No of subtrees with sum  " << x << " is : " << ans << endl;
}  