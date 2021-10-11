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
    cout << "Enter the data" << endl;
    cin >> x;
    if (x == -1)
        return NULL;
    node *new_node = new node(x);
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
    cout << "Enter the data of the root node " << endl;
    cin >> x;
    root = new node(x); 
    // first create the root nod
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
            temp = new node(x);
            // creating the new node for the left child
            p->left = temp;
            // making the current nodes left pointing to newly created node,which is left child of current node
            q.push_back(temp);
            // pushing the left child into queue,because we also want to create childs of this node too
        } 
        cout << "Enter the right child of the node : " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            temp = new node(x);
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
    tree.create();
    cout << "preorder traversal of the binary tree is : " << endl;
    tree.preorder(root);
    cout << endl;
    cout << "inorder traversal of the binary tree is : " << endl;
    tree.inorder(root);
    cout << endl;
    cout << "postorder traversal of the binary tree is : " << endl;
    tree.postorder(root);
} 