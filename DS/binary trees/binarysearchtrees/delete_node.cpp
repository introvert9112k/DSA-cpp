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
    Node *extremeright(Node *curr)
    {
        while (curr->right)
            curr = curr->right;
        return curr;
    }
    Node *helper(Node *curr)
    {
        if (curr->left == NULL)
            return curr->right;
        else if (curr->right == NULL)
            return curr->left;
        Node *exright = extremeright(root->left);
        exright->right = curr->right;
        return curr->left;
    } 
    Node *deleteNode(Node *root, int target)
    {
        if (root == NULL)
            return NULL;
        if (root->data == target)
        {
            root = helper(root);
        }
        Node *temp = root;
        while (root != NULL)
        {
            if (root->data > target)
            {
                if (root->left and root->left->data == target)
                {
                    root->left = helper(root->left);
                    break;
                }
                root = root->left;
            }
            else
            {
                if (root->right and root->right->data == target)
                {
                    root->right = helper(root->right);
                    break;
                }
                root = root->right;
            }
        }
        return temp;
    }
    // strivers playlist
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
    int target;
    cout << "enter the target" << endl;
    cin >> target;
    cout << "nodes before deleting the target node" << endl;
    tree.inorder(root);
    cout << endl;
    tree.deleteNode(root, target);
    cout << "nodes after deleting the target node" << endl;
    tree.inorder(root);
}
