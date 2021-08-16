#include <bits/stdc++.h>

using namespace std;
class node
{
public:
    node *left;
    int data;
    node *right;
};
node *root = NULL;
class binarytree
{
public:
    // constructing binary search tree from preorder traversal
    void preconstruct(int *arr, int n)
    {
        stack<node *> stack;
        // stack for storing the node*
        int i = 0;
        // for iterating over the array of preorder traversals
        // first create a new node,and put first element value as data to it,and make this node as root node
        root = new node;
        root->data = arr[i++];
        // after assing the value increment the i ,so i points to next element in array
        root->left = root->right = NULL;
        // current pointer is for iterating
        node *current = root;
        while (i < n)
        {
            if (arr[i] < current->data)
            {
                // if the element in array is less than the current node data,then make a new node,assingn the array element value to it,and make current node left pointing to the newly created node
                // and push the current node into the stack,and update the current node

                // and also increment the i
                node *temp = new node;
                temp->data = arr[i++];
                temp->left = temp->right = NULL;
                current->left = temp;
                stack.push(current);
                current = temp;
            }
            else
            {
                // if array element is greater than the current node value
                // Then check whether the value lies in between the current node data and the node data which is at top of the stack, if stack is empty take the value of the top node of the stack as infinity

                // if this condition is met,then create a new node, make it as right child to current node,and increment i and update teh current node
                // do not push the curretn node into stack

                if ((arr[i] > current->data) and (stack.empty() or (arr[i] < stack.top()->data)))
                {
                    node *temp = new node;
                    temp->data = arr[i++];
                    temp->right = temp->left = NULL;
                    current->right = temp;
                    current = temp;
                }
                // if the above conditon is not met,pop the top node from stack and assign it to current
                // do not increment i
                else
                {
                    current = stack.top();
                    stack.pop();
                }
            }
        }
    } 
    void inorder(node *temp = root)
    {
        if (temp == NULL)
            return;

        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    }
};

int main()

{
    binarytree tree;
    int n;
    cin >> n;
    int arr[n];
    cout << "Enter the preorder traversal of the binary search tree : " << endl;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    tree.preconstruct(arr, n);
    cout << "inorder traversal of the tree is  : " << endl;
    tree.inorder();

    return 0;
} 