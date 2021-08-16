#include <iostream>
#include <string>
#include <algorithm>

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
    // in this function we are traversing the all the nodes,and checking whether any of the node matches with either n1 or n2, if mathces set corresponding booleans to true
    void find(node *node1, int n1, int n2, bool &v1, bool &v2)
    {
        if (node1 == NULL)
            return;
        find(node1->left, n1, n2, v1, v2);
        find(node1->right, n1, n2, v1, v2);
        if (node1->data == n1)
            v1 = true;
        if (node1->data == n2)
            v2 = true;
    }
    // for a given node,if n1 and n2 are present in different subtrees of node then node is the lca of n1 and n2
    node *findlca(node *root, int n1, int n2)
    {
        // so for a given node,if left and right subtree not returns NULL value then that node is lca
        // base conditon
        if (root == NULL)
            return NULL;
        // if n1 or n2 is found retun that node
        if (root->data == n1 || root->data == n2)
            return root;
        // checking in left and right subtrees of the node
        node *left1 = findlca(root->left, n1, n2);
        node *right1 = findlca(root->right, n1, n2);
        // if both the trees does not return NULL value, then it is the lca and return it
        if (left1 && right1)
            return root;
        // if any one of the subtree not returns NULL then return it
        return left1 != NULL ? left1 : right1;
    } 
    // Ancestor of a node is defined as the nodes which are along the path from root node to the current node,Lowest common ancestor is the node which is common to the both the nodes and farther from the root

    // if the one of the given node is ancestor of the other node ,then lca would be this node
    // this is function to find the lca of given two nodes
    node *lca(node *root, int n1, int n2)
    {
        //    There may be cases that the given two nodes are not present in tree, or either one present and another is not present
        // In cases where both are not present, only one is present lca would be null
        // so we check whether the two nodes are present in the tree or not
        // intially boolean v1 and v2 are set as false after checking if we find node1 then v1 become true similarly with v2
        bool v1 = false, v2 = false;
        // function for finding node1 and node2
        find(root, n1, n2, v1, v2);
        // if both the nodes are present we check for their common ancestor,else return NULLL
        if (v1 && v2)
        {
            // function for finding the lca
            return findlca(root, n1, n2);
        }
        else
            return NULL;
    }
};
int main()

{
    binarytree tree;
    node *root = tree.create();
    tree.preorder(root);
    cout << endl;
    int n1, n2;
    cin >> n1 >> n2;
    cout << "common ancestor of  " << n1 << " " << n2 << "is " << tree.lca(root, n1, n2)->data << endl;
    return 0;
}
