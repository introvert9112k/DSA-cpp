// problem statement
// given an binary tree,we should say whether the binary tree is balanced or not
// A tree is said to be balanced when for every node the difference difference between the height of left and right subtree is less than or equal to 1

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

//  --------------------this is brute force approach---------------------------------------------

// for every node we would check that the differnce between the height of left and right subtree is <= 1 ,if for any node this case fails then the tree is not balanced binary tree

// code for finding the height of the given node
int height(node *temp)
{
    if (!temp)
        return 0;
    int lh = height(temp->left);
    int rh = height(temp->right);
    return 1 + max(lh, rh);
}
void balanced1(node *temp)
{
    if (!temp)
        return true;
    // finding the left and right height of the current node
    int leftht = height(temp->left);
    int rightht = height(temp->right);
    // if there absolute difference is > 1 then return false,no need to check for furhter nodes in traverse
    if (abs(lefthht - righthht) > 1)
        return false;
    // for a given node left and right stores the boolean returned by left subtree and right subtrees
    bool left = balanced1(temp->left);
    bool right = balanced1(temp->right);
    // if any of the subtrees return false then return false else return true
    if (!left or !right)
        return false;
    return true;
} 

// Time complexity ------------O(N*N) as we are traversing each node and finding the left and right subtree heights for each nod
// Space Complexity ---------O(N*N)

// ----------------------brute force end-------------------------------------



// -----------------Effiecent Approach------------------

int balanced(node* temp)
{
    if(!temp)
        return 0;
    // lh and rh stores the left and right subtrees height of the node
    int lh =  balanced(temp->left);
    int rh = balanced(temp->right);
    // for given node if lh or rh is -1 then return -1
    if(lh == -1 or rh == -1)
        return -1;
    // if the abs difference of heights is >1 then return -1
    if(abs(lh-rh) > 1)
        return -1;
    return 1 + max(lh, rh);
} 
// the code will return -1 if the tree is not balanced,else returns height of the tree if it is balanced

// Time complexity O(N as we are traversing only once

// --------------------------Efficent approach end--------------------
int main()
{
    root = construct();
    inorder(root);
    if(balanced(root)!=-1)
        cout << "balanced" << endl;
    else
        cout << "Not balanced" << endl;
} 