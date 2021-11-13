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

// maximum value in left subtree
int maxleft(node *root, node *temp)
{
    int lmax, rmax, maxval;
    if (!temp)
        return INT_MIN;
    // lmax is the maximum value in left subtree
    lmax = maxleft(root, temp->left);
    // rmax is the maximum value in the right subtree
    rmax = maxleft(root, temp->right);
    // maxval is the global maximum of the current tree
    maxval = max({lmax, rmax, temp->data});
    // we need to find the max of left subtree so when we recursively return to root node then we return the lmax until now, that mean the  maximum of the left subtreee
    if (temp == root)
        return lmax;
    else
        return maxval;
    // if there is no left subtree for the given node then it will return the value of the given node

    // -----dry running will give better understanding-------------
}

// maximum value in right subtree
int maxright(node *root, node *temp)
{
    int lmax, rmax, maxval;
    if (!temp)
        return INT_MIN;
    lmax = maxleft(root, temp->left);
    rmax = maxleft(root, temp->right);
    maxval = max({lmax, rmax, temp->data});
    if (temp == root)
        return rmax;
    else
        return maxval;
}

// minimum value in left subtree
int minleft(node *root, node *temp)
{
    int lmin, rmin, minval;
    if (!temp)
        return INT_MAX;
    lmin = minleft(root, temp->left);
    rmin = minleft(root, temp->right);
    minval = min({lmin, rmin, temp->data});
    if (temp == root)
        return lmin;
    else
        return minval;
}

// minimum value in right subtree
int minright(node *root, node *temp)
{
    int lmin, rmin, minval;
    if (!temp)
        return INT_MAX;
    lmin = minleft(root, temp->left);
    rmin = minleft(root, temp->right);
    minval = min({lmin, rmin, temp->data});
    if (temp == root)
        return rmin;
    else
        return minval;
}

int main()

{
    binarytree tree;
    node *root = tree.create();
    tree.preorder(root);
    cout << endl;
    cout << "maxvalue in left subtree is " << maxleft(root, root) << endl;
    cout << "maxvalue in right subtree is " << maxright(root, root) << endl;
    cout << "minvalue in left subtree is " << minleft(root, root) << endl;
    cout << "minvalue in right subtree is " << minright(root, root) << endl;
    return 0;
} 