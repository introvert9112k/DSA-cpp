// problem statment
// given a tree we should find the diameter of the tree
#include <bits/stdc++.h>
using namespace std;
struct node
{
    node *left;
    int data;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
node *root = NULL;
node *construct()
{
    int x;
    cout << "Enter the data" << endl;
    cin >> x;
    if (x == -1)
        return NULL;
    node *curr = new node(x);
    cout << "Enter the left child of the node " << curr->data << endl;
    curr->left = construct();
    cout << "Enter the right child of the node " << curr->data << endl;
    curr->right = construct();
    return curr;
}
void inorder(node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}

// ------------brute force approach--------------
// The diameter of a tree (sometimes called the width) is the number of nodes on the longest path between two end nodes.
// path may or may not pass through the root node
// for every node no of nodes in maximum path length is given by (leftheight + rightheight + 1),diameter is the maximum of all these paths,so for all nodes we calculate the length of the path and take the maximum of these paths

// ---------------------Brute force approach---------------------
int height(node *temp)
{
    if (!temp)
        return 0;
    int lh = height(temp->left);
    int rh = height(temp->right);
    return 1 + max(lh, rh);
}
void diameter1(node *temp, int &dia)
{
    if (!temp)
        return;
    // dia stores the max path values
    // lh and rh stores the  height of the left and right subtrees
    int lh = height(temp->left);
    int rh = height(temp->right);
    dia = max(dia, lh + rh + 1);
    diameter1(temp->left, dia);
    diameter1(temp->right, dia);
}
// Time complexity O(N*N
// space O(N*N)

// -------------------Brute force approach--------------------

// --------------------efficent approach--------------------
int diameter(node *temp, int &dia)
{
    if (!temp)
        return 0;
    int lh = diameter(temp->left, dia);
    int rh = diameter(temp->right, dia);
    dia = max(dia, lh + rh + 1);
    return 1 + max(lh, rh);
}
// Time and Auxilary space O(N)

// ----------------------efficent approach------------------

int main()
{
    root = construct();
    inorder(root);
    int dia = 0;
    diameter(root, dia);
    cout << "diameter of the tree is " << dia << endl;
}