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
    int ceil(int key)
    {
        Node *curr = root;
        int ceil = -1;
        while (curr)
        {
            if (curr->data == key)
                return curr->data;
            if (key < curr->data)
            {
                ceil = curr->data;
                curr = curr->left;
            }
            else
                curr = curr->right;
        }
        return ceil;
    }
    int floor(int key)
    {
        Node *curr = root;
        int floor = -1;
        while (curr)
        {
            if (curr->data == key)
                return curr->data;
            if (key < curr->data)
                curr = curr->left;
            else
            {
                floor = curr->data;
                curr = curr->right;
            }
        }
        return floor;
    }
    // time complexity of floor and ceil is O(logN)
    // The maximum height of the bst is logN
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
    int y;
    cout << "enter the number" << endl;
    cin >> y;
    cout << "ceil is  :  " << tree.ceil(y) << "  floor is : " << tree.floor(y) << endl;
}