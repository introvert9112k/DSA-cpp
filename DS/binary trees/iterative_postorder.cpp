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
void postorder(node *temp)
{
    if (!temp)
        return;
    postorder(temp->left);
    postorder(temp->right);
    cout << temp->data << " ";
}
// iterative postorder using the two stacks
void iterative_postorder(node *root)
{
    stack<node *> stack1;
    stack<int> stack2;
    // take two stacks one for storing the nodes and other for storing the postorder traversal
    // push the root into stack
    stack1.push(root);
    while (!stack1.empty())
    {
        // pop the node from the stack1 and push the popped nodes data into stack2
        node *temp = stack1.top();
        stack1.pop();
        stack2.push(temp->data);
        // if left child exists then push it into stack1
        if (temp->left)
            stack1.push(temp->left);
        // if right child exists push into stack1
        if (temp->right)
            stack1.push(temp->right);
    }
    // after the iteration the stack2 contains the post order traversal of the tree
    // print the stack elements one by one
    while (!stack2.empty())
    {
        cout << stack2.top() << " ";
        stack2.pop();
    }
}
int main()
{
    root = construct();
    cout << "recursive Post order traversal " << endl;
    postorder(root);
    cout << "Iterative post order traversal  " << endl;
    iterative_postorder(root);
} 