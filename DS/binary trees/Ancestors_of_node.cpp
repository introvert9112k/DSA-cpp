#include <bits/stdc++.h>
using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;
    }
}; 
class binarytree
{
public:
    node *create()
    {
        node *new_node;
        int x;
        cout << "Enter the data" << endl;
        cin >> x;
        if (x == -1)
            return NULL;
        new_node = new node(x);
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
    // code for ancestors
    node *ancestors1(node *node1, int target, vector<int> &v)
    {
        // base case
        if (node1 == NULL)
            return NULL;
        // traverse the tree
        node *left = ancestors1(node1->left, target, v);
        node *right = ancestors1(node1->right, target, v);
        // if target is found return the node insted of the NULL
        if (node1->data == target)
            return node1;
        // if any of the subtrees of the node returns not NULL , then that node will be one of the ancestor of the node, push that into vector and returns the not NULL value
        else if (left != NULL or right != NULL)
        {
            v.push_back(node1->data);
            return left != NULL ? left : right;
        }
        // if both trees returns null then that node is not ancestor of our node ,return NULL
        else
            return NULL;
    }
    // driving code for finding the ancesrtors
    vector<int> ancestors(struct node *root, int target)
    {
        vector<int> v;
        ancestors1(root, target, v);
        return v;
    }
};
int main()

{
    binarytree tree;
    node *root = tree.create();
    tree.preorder(root);
    cout << endl;
    int n;
    cin >> n;
    vector<int> v = tree.ancestors(root, n);
    cout << "The ancestors of the " << n << "are " << endl;
    for (auto val : v)
        cout << val << " ";
    // given a node we should find the all the ancestors of the node

    return 0;
} 