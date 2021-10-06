// problem statement
// given a tree we should say whether the tree is binary search tree or not
// there are many methods to do it

#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
};
class binarytree
{
public:
    node *create()
    {
        node *new_node;
        int x;
        static int i = 0;
        if (i == 0)
        {
            cout << "Enter the value of the root node" << endl;
            i++;
        }
        cin >> x;
        if (x == -1)
            return NULL;
        new_node = new node;
        new_node->data = x;
        new_node->left = new_node->right = NULL;
        cout << "Enter the left child of the node  " << new_node->data << endl;
        new_node->left = create();
        cout << "Enter the right child of the node " << new_node->data << endl;
        new_node->right = create();
        return new_node;
    }
    void preorder(node *temp)
    {
        if (temp == NULL)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
};

// -----------------METHOD1 ---------------------
// inorder traversal of binary tree gives sorted order,so collect the node values in a vector and check whether the vector is sorted or not if sorted then binary tree is bst else not bst
vector<int> arr;
void inorder1(node *root)
{
    if (!root)
        return;
    inorder1(root->left);
    arr.push_back(root->data);
    inorder1(root->right);
}
bool checksorted()
{
    for (int i = 1; i < arr.size(); i++)
        if (arr[i - 1] > arr[i])
            return false;
    return true;
}
// ------------------METHOD1--------------------

// ------------------METHOD2------------------
// In bst every subtree is also binary search tree, so maximum value in left subtree is less than current node data and minimum value in right subtree is greater than the current node data, if this condition valid for every node then it is bst

// code for finding the maximum element in left subtree
int maxleft(node *root, node *temp)
{
    int lmax, rmax, maxval;
    if (!temp)
        return INT_MIN;
    lmax = maxleft(root, temp->left);
    rmax = maxleft(root, temp->right);
    maxval = max({lmax, rmax, temp->data});
    if (temp == root)
        return lmax;
    else
        return maxval;
    // if there is no leftsubtree it returns INT_MIN
}
// code for finding minimum element in right subtree
int minright(node *root, node *temp)
{
    int lmin, rmin, minval;
    if (!temp)
        return INT_MAX;
    int lmin = minright(root, temp->left);
    int rmin = minright(root, temp->right);
    minval = min({lmin, rmin, temp->data});
    if (temp == root)
        return rmin;
    else
        return minval;
    // if there is no rightsubtree it returns INT_MAX
}
int checkbst(node *root)
{
    // if the node is null then return 1
    if (!root)
        return 1;
    // if there is left subtree and max in left subtree is greater than the current node data then return 0
    if (root->left != NULL and maxleft(root) > root->data)
        return 0;
    // if there is right subtree and minimum in right subtree is less than the current node data then return 0
    if (root->right != NULL and minright(root) < root->data)
        return 0;
    // recursively check for false condition in left and right subtrees
    if (!checkbst(root->left) or !checkbst(root->right))
        return 0;
    // if all the above conditions fails then the tree is binary search tree so return 1
    return 1;
    // here we are checking from root node onwards
} 

// --------METHOD2-------------------
int main()

{
    binarytree tree;
    node *root = tree.create();
    method1(root);

    return 0;
}