#include <bits/stdc++.h>
using namespace std;

struct node
{
    struct node *left;
    int data;
    struct node *right;
};
struct node *root = NULL;
void create()
{
    deque<struct node *> q;
    // deque for storing the address of the nodes
    int x;
    struct node *temp, *p;
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
    // in this approach we are creating the tree level by level,that mean first we finish the level and after that we go for another level
}

struct node *rcreate()
{
    // this is recursive approach for creating the binary tree
    int x;
    // for storing the data of the newly created node
    static int i = 0;
    // for identification of the root node
    if (i == 0)
    {
        cout << "Enter the root node value " << endl;
        //   if i==0 then it is root node,else it is internal node
        i++;
    }
    cin >> x;
    // reading the input from stdin
    if (x == -1)
        // base case,if there is no child either right or left return NULL
        return NULL;
    // if x is not -1,then create a new node
    struct node *new_node = new node;
    // assinging the data of the node
    new_node->data = x;
    // making left and right pointers poiting to null,this is very important because if we not made them to null,they will store some garbage values which points to another locations,this leads to wrong output in the traversals
    new_node->right = new_node->left = NULL;

    cout << "Enter the left child of the node  " << new_node->data << endl;
    // getting the data of the left child for the current node
    new_node->left = rcreate();
    // getting the data of the right child of the current node
    cout << "Enter the right child of the node  " << new_node->data << endl;
    new_node->right = rcreate();
    // returning the  current node
    return new_node;

    // In this approach we are not consturcting the binary tree level by level, first we are creating the left childs of the nodes,after that in reverse traverse we are creating the right childs

    // Time complexity is o(2*n +1)
    // because if there are n nodes there will be n+1 null pointers, recursive calls are called for n nodes and n+1 null nodes,so time complexity is n + n +1 =2*n +1

    // Auxilary space is O(N)
    // precisely it is equal to the no of levels in tree +1,+1 is for null nodes,for them also activation record
    // is created
}

struct node *rcreate2()
{
    int x;
    static int i = 0;
    if (i == 0)
    {
        cout << "Enter the root node value " << endl;
        i++;
    }
    cin >> x;
    if (x == -1)
        return NULL;
    struct node *new_node = new node;
    new_node->data = x;
    new_node->right = new_node->left = NULL;
    cout << "Enter the right child of the node  " << new_node->data << endl;
    new_node->right = rcreate2();
    cout << "Enter the left child of the node  " << new_node->data << endl;
    new_node->left = rcreate2();
    return new_node;

    // In this approach we are not consturcting the binary tree level by level, first we are creating the right childs of the nodes,after that in reverse traverse we are creating the left childs
}
void preorder(struct node *temp)
{
    if (temp == NULL)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void inorder(struct node *temp)
{
    if (temp == NULL)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void postorder(struct node *temp)
{
    if (temp == NULL)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}
void iterative_preorder(struct node *temp = root)
{
    // iterative approach for preorder
    stack<struct node *> stack;
    while (temp != NULL or !stack.empty())
    {
        if (temp != NULL)
        {
            cout << temp->data << " ";
            stack.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = stack.top();
            stack.pop();
            temp = temp->right;
        }
    }
}
void iterative_inorder(struct node *temp = root)
{
    // iterative approach for inorder
    stack<struct node *> stack;
    while (temp != NULL or !stack.empty())
    {
        if (temp != NULL)
        {
            stack.push(temp);
            temp = temp->left;
        }
        else
        {
            temp = stack.top();
            stack.pop();
            cout << temp->data << " ";
            temp = temp->right;
        }
    }
}

int main()
{
    root = rcreate(); //for recursive construction of the tree
    // create() //for iterative construction of tree
    cout << "preorder traversal of the binary tree is : " << endl;
    preorder(root);
    cout << endl;
    // cout << "iterative preorder traversal of the binary tree is : " << endl;
    // iterative_preorder(root);
    // cout << endl;
    cout << "inorder traversal of the binary tree is : " << endl;
    inorder(root);
    cout << endl;
    // cout << "iterative inorder traversal of the binary tree is : " << endl;
    // iterative_inorder(root);
    // cout << endl;
    cout << "postorder traversal of the binary tree is : " << endl;
    postorder(root);
}