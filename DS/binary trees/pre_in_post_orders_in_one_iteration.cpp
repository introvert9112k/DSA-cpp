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
// recursive way to find the preorder,inorder,and postorder in one iteration
// time complexity is o(N)
// space complexity is O(N) auxilary space

void traversal(node *temp, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    if (!temp)
        return;
    preorder.push_back(temp->data);
    traversal(temp->left, preorder, inorder, postorder);
    inorder.push_back(temp->data);
    traversal(temp->right, preorder, inorder, postorder);
    postorder.push_back(temp->data);
}

// time complexity O(3N) we are visting every node for atmost 3 times,so time complexity is 3N
// space complexity o(3N) for pre,in and post vectors

// ------------------------------------------------------------------------------------------------------------------------------------------

// rules to be followed
// create a stack of node* and int combination
// first push the root node and value 1 combination into stack
// 1 determines that it belongs to preorder,2 for inorder and 3 for postorder

// now iterate until the stack is empty

// now pop the element from the stack

// ----------------------------------------if the value is 1-----------------------------------------
// That mean it belong to preorder,push the node's data into preorder and now push {node,2} combination into stack, if the left child of the  current node exists then push the {node->left,1} into stack

// ---------------------------------------if the value is 2--------------------------------------
// that mean it belong to the inorder, push the node data into the inorder and now push {node,3} combination into stack,if the right child of the current node exists then push the {node->right,1} into stack

// ----------------------------------------if the value is 3--------------------------------------
// that mean it belong to the postorder,push the node data into the postorder and do nothing

// repeat these steps until the stack is not empty

// ----------------------------------------------------------------------------------------------------------------------------------------
void iterative_traversal(node *root, vector<int> &preorder, vector<int> &inorder, vector<int> &postorder)
{
    stack<pair<node *, int>> stack;
    stack.push({root, 1});
    while (!stack.empty())
    {
        node *temp = stack.top().first;
        int num = stack.top().second;
        stack.pop();
        if (num == 1)
        {
            preorder.push_back(temp->data);
            stack.push({temp, 2});
            if (temp->left)
                stack.push({temp->left, 1});
        }
        else if (num == 2)
        {
            inorder.push_back(temp->data);
            stack.push({temp, 3});
            if (temp->right)
                stack.push({temp->right, 1});
        }
        else
        {
            postorder.push_back(temp->data);
        }
    }
}
int main()
{
    root = construct();
    vector<int> preorder, inorder, postorder;
    iterative_traversal(root, preorder, inorder, postorder);
    cout << "preorder" << endl;
    for (auto x : preorder)
        cout << x << " ";
    cout << endl;
    cout << "inorder" << endl;
    for (auto x : inorder)
        cout << x << " ";
    cout << endl;
    cout << "postorder" << endl;
    for (auto x : postorder)
        cout << x << " ";
} 