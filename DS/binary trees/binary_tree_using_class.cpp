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
    void create();
    node *rcreate();
    void preorder(node *);
    void inorder(node *);
    void postorder(node *);
};
node *root = NULL;

node *binarytree::rcreate()
{
    // recursive way to construct a binary tree
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
    node *new_node = new node;
    new_node->data = x;
    new_node->right = new_node->left = NULL;
    cout << "Enter the left child of the node " << new_node->data << endl;
    new_node->left = rcreate();
    cout << "Enter the right child of the node " << new_node->data << endl;
    new_node->right = rcreate();
    return new_node;
}
void binarytree::create()
{
    deque<node *> q;
    // deque for storing the address of the nodes
    int x;
    node *temp, *p;
    // p points to the current node,and temp is used for creating the left and right childs of the current node
    root = new node;
    // first create the root node
    root->left = root->right = NULL;
    // make left and right child of the root to NULL
    cout << "Enter the data of the root node " << endl;
    // reading the data of the root node
    cin >> root->data;
    q.push_back(root);
    // pushing the root node into the queue for creating the right child and left child for the root node
    while (!q.empty())
    { //iterate until the queue is not empty
        p = q.front();
        // getting the front node in the queue
        q.pop_front();
        // for this node,we are creating left and right childs,so we further don't require it so pop it from queue
        cout << "Enter the left child of the node  : " << p->data << endl;
        // reading the data of the left child
        cin >> x;
        // if the entered value is -1,that mean there is no child for that node,if not there is child
        if (x != -1)
        {
            temp = new node;
            // creating the new node for the left child
            temp->data = x;
            temp->left = temp->right = NULL;
            // Assinging the value
            p->left = temp;
            // making the current nodes left pointing to newly created node,which is left child of current node
            q.push_back(temp);
            // pushing the left child into queue,because we also want to create childs of this node too
        }
        cout << "Enter the right child of the node : " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            temp = new node;
            temp->data = x;
            temp->left = temp->right = NULL;
            p->right = temp;
            // making the current node right pointing to newly created node,which is right child of current node
            q.push_back(temp);
            // pushing the right child into queue,because we also want to create childs of this node too
        }
    }
}

void binarytree::preorder(node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void binarytree::inorder(node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void binarytree::postorder(node *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
} 
int main()
{
    binarytree tree;
    root = tree.rcreate();
    cout << "preorder traversal of the binary tree is : " << endl;
    tree.preorder(root);
    cout << endl;
    cout << "inorder traversal of the binary tree is : " << endl;
    tree.inorder(root);
    cout << endl;
    cout << "postorder traversal of the binary tree is : " << endl;
    tree.postorder(root);
}