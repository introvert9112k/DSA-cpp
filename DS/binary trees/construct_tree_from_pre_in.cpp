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
Node *construct(vector<int> &preorder, int pstart, int pend, vector<int> &inorder, int instart, int inend, unordered_map<int, int> &inmap)
{
    if (pstart > pend or instart > inend)
        return NULL;
    Node *root = new Node(preorder[pstart]);
    int inroot = inmap[preorder[pstart]];
    int numsleft = inroot - instart;

    root->left = construct(preorder, pstart + 1, pstart + numsleft, inorder, instart, inroot - 1, inmap);
    root->right = construct(preorder, pstart + numsleft + 1, pend, inorder, inroot + 1, inend, inmap);
    return root;
}
void postorder(Node *root)
{
    if (!root)
        return;
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
} 
int main()

{
    int n;
    cout << "enter the no of nodes in binary tree" << endl;
    cin >> n;
    vector<int> preorder(n), inorder(n);
    cout << "enter the preorder traversal of the tree" << endl;
    for (int i = 0; i < n; i++)
        cin >> preorder[i];
    cout << "enter the inorder traversal of the tree" << endl;
    unordered_map<int, int> inmap;
    for (int i = 0; i < n; i++)
    {
        cin >> inorder[i];
        inmap[inorder[i]] = i;
    }
    Node *root = construct(preorder, 0, n - 1, inorder, 0, n - 1, inmap);
    cout << "post order traversal of the tree is :" << endl;
    postorder(root);
    return 0;
} 