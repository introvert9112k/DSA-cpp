#include <bits/stdc++.h>
using namespace std;

struct node
{
    node *left, *right;
    int data;
    // node *right;
    node(int x)
    {
        data = x;
        left = right = NULL;

        // making left and right pointers poiting to null,this is very important because if we not made them to null,they will store some garbage values which points to another locations,this leads to wrong output in the traversals
    }
};
node *root = NULL;
void create()
{
    deque<node *> q;
    // deque for storing the address of the nodes
    int x;
    node *p;
    // p points to the current node
    cout << "Enter the data of the root node " << endl;
    cin >> x;
    // creating a new node with value x
    root = new node(x);
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
            p->left = new node(x);
            // making the current nodes left pointing to newly created node,which is left child of current node
            q.push_back(p->left);
            // pushing the left child into queue,because we also want to create childs of this node too
        }
        cout << "Enter the right child of the node : " << p->data << endl;
        cin >> x;
        if (x != -1)
        {
            p->right = new node(x);
            // making the current node right pointing to newly created node,which is right child of current node
            q.push_back(p->right);
            // pushing the right child into queue,because we also want to create childs of this node too
        }
    }
    // in this approach we are creating the tree level by level,that mean first we finish the level and after that we go for another level
}

node *rcreate()
{
    // this is recursive approach for creating the binary tree
    int x;
    // for storing the data of the newly created node
    cout << " Enter the data " << endl;
    cin >> x;
    // reading the input from stdin
    if (x == -1)
        // base case,if there is no child either right or left return NULL
        return NULL;
    // if x is not -1,then create a new node
    node *curr = new node(x);
    cout << "Enter the left child of the node  " << curr->data << endl;
    // getting the data of the left child of the current node
    curr->left = rcreate();
    cout << "Enter the right child of the node " << curr->data << endl;
    // getting the data of the right child for the current node
    curr->right = rcreate();
    // returning the  current node
    return curr;

    // In this approach we are not consturcting the binary tree level by level, first we are creating the left childs of the nodes,after that in reverse traverse we are creating the right childs

    // Time complexity is o(2*n +1)
    // because if there are n nodes there will be n+1 null pointers, recursive calls are called for n nodes and n+1 null nodes,so time complexity is n + n +1 =2*n +1

    // Auxilary space is O(N)
    // precisely it is equal to the no of levels in tree +1,+1 is for null nodes,for them also activation record
    // is created
}

// construct binary tree from the array of elements
// array contains the level order traversal of the elements

node *constructtree(vector<int> &arr, int i, int n)
{
    if (i >= n or arr[i] == -1)
        return NULL;

    node *new_node;
    new_node = new node(arr[i]);
    new_node->left = constructtree(arr, 2 * i + 1, n);
    new_node->right = constructtree(arr, 2 * i + 2, n);

    return new_node;
}

node *rcreate2()
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
    struct node *new_node = new node(x);
    cout << "Enter the right child of the node  " << new_node->data << endl;
    new_node->right = rcreate2();
    cout << "Enter the left child of the node  " << new_node->data << endl;
    new_node->left = rcreate2();
    return new_node;

    // In this approach we are not consturcting the binary tree level by level, first we are creating the right childs of the nodes,after that in reverse traverse we are creating the left childs
} 
void preorder(node *temp)
{
    if (!temp)
        return;
    cout << temp->data << " ";
    preorder(temp->left);
    preorder(temp->right);
}
void inorder(node *temp)
{
    if (!temp)
        return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
}
void postorder(node *temp)
{
    if (!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}
void iterative_preorder(node *temp = root)
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