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
node *create()
{
    int x;
    cout << "Enter the data" << endl;
    cin >> x;
    if (x == -1)
        return NULL;
    node *new_node = new node(x);
    cout << "Enter the left child of the node " << new_node->data << endl;
    new_node->left = create();
    cout << "Enter the right child of the node " << new_node->data << endl;
    new_node->right = create();
    return new_node;
}
void preorder(node *temp)
{
    if (!temp)
        return;
    cout << temp->data << endl;
    preorder(temp->left);
    preorder(temp->right);
}
void leftboundary(vector<int> &ans)
{
    // start from the left node of the root,if the current node is not a leaf node then
    // push into the vector,if the left child exists for current node then move to left child,
    // if the left child does not exists then move to the right child,if both childs does not
    // exist then stop iterating
    node *temp = root->left;
    while (temp)
    {
        if (temp->left or temp->right)
            ans.push_back(temp->data);
        if (temp->left)
            temp = temp->left;
        else if (temp->right)
            temp = temp->right;
        else
            temp = NULL;
    }
}
void leafnodes(node *temp, vector<int> &ans)
{
    // simple code for finding the leaf nodes
    if (!temp)
        return;
    leafnodes(temp->left, ans);
    leafnodes(temp->right, ans);
    if (!temp->left and !temp->right)
        ans.push_back(temp->data);
}
void rightboundary(vector<int> &ans)
{
    // the logic is same as finding leftboundary values, start from the right child of the root
    // if the current node is not leaf node then push into stack,if the right child exists then
    // move to right child,else if left child exists then move to left child,if both childs does
    // not exist then stop iterating

    // we have to insert the values into vector in reverse order so we have stored the values
    // in stack and later popped all values from stack and inserted into vector
    node *temp = root->right;
    stack<int> stack;
    while (temp)
    {
        if (temp->left or temp->right)
            stack.push(temp->data);
        if (temp->right)
            temp = temp->right;
        else if (temp->left)
            temp = temp->left;
        else
            temp = NULL;
    }
    while (!stack.empty())
    {
        ans.push_back(stack.top());
        stack.pop();
    }
}
vector<int> boundarytraversal()
{
    vector<int> ans;
    // if the root is null then return the empty vector
    if (!root)
        return ans;
    // if the root is not leaf node then include it in the vector
    if (root->left or root->right)
        ans.push_back(root->data);
    // if there exists only root node and there is no left and right subtrees then root node will be left and right boundary
    // this would be included in the leafnode
    leftboundary(ans);
    leafnodes(root, ans);
    rightboundary(ans);
    return ans;
}
int main()
{
    root = create();
    vector<int> ans = boundarytraversal();
    for (auto x : ans)
        cout << x << " ";
}