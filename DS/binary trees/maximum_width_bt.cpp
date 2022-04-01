// problem statement
// Given the root of a binary tree, return the maximum width of the given tree.

// The maximum width of a tree is the maximum width among all levels.

// The width of one level is defined as the length between the end-nodes (the leftmost and rightmost non-null nodes), where the null nodes between the end-nodes are also counted into the length calculation.

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
};
// Intution
// we assign the index value to the each node
// Maxwidth int the particular level is the difference between lefmostNode index - RightmostNode Index +1
// if the parent node is at ith index then left child is at 2*i+1 and right child is at 2*i+2
// Intially the root node is at index 0,using bfs we assign the indexes values to the node
// If we use navie approach using formula 2*i+1,2*i+2 it causes overflow
// So in every we start from the index 0 only, to do this we subtract the minvalue in that level from the node index and apply 2*i+1 and 2*i+2 formulas
// In large bts this may also causes overflow,so better use long long

// Refererence : Striver trees playlist
int MaxWidthofBT(Node *root) 
{
    queue<pair<Node *, long long>> q;
    q.push({root, 0});
    int MaxWidth = INT_MIN;
    while (!q.empty())
    {
        int size = q.size();
        int MinInd = q.front().second; // In every level min ind is the Index of the first Node in that level
        int LeftmostInd, RightmostInd; // For storing leftmost and rightmost index values
        for (int i = 0; i < size; i++)
        {
            Node *Curr = q.front().first;
            int NodeIndex = q.front().second - MinInd;
            if (i == 0)
                LeftmostInd = NodeIndex;
            if (i == size - 1)
                RightmostInd = NodeIndex;
            if (Curr->left)
                q.push({Curr->left, 1LL * 2 * NodeIndex + 1});
            if (Curr->right)
                q.push({Curr->right, 1LL * 2 * NodeIndex + 2});
        }
        MaxWidth = max(MaxWidth, RightmostInd - LeftmostInd + 1);
    }
    return MaxWidth;
}
int main()
{
    binarytree tree;
    Node *root = tree.construct();
} 