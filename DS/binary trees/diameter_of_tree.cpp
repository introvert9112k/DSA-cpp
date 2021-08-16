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
    // function to find the height of the binary tree
    int height(node *temp)
    {
        if (temp == NULL)
            return 0;
        int x = height(temp->left);
        int y = height(temp->right);
        return max(x, y) + 1;
    }
    int diameter(node *temp)
    {
        if (temp == NULL)
            return 0;
        //   diameter is nothing but the no of nodes along the maximum path between two leaf nodes
        //    maximum path may pass throught the root or not, so we should consider both cases passing through root and not passing
        // if maximum path includes root then diameter will be left subtree height + right subtree height +1
        // if not includes then it would be the maximum diamaetr of the left subtree and right subtree
        // we do not know whether the path contains root or not,so we calculate for the both cases and take maximum out of these values

        //   finding the height of the left subtree
        int lheight = height(temp->left);
        //    finding the height of the right subtree
        int rheight = height(temp->right);

        // finding the diameter of the left subtree
        int ldiameter = diameter(temp->left);
        // finding the diameter of the right subtree
        int rdiameter = diameter(temp->right);
        // returning the max of the both the cases
        return max(lheight + rheight + 1, max(ldiameter, rdiameter));
    }
};
int main()

{
    binarytree tree;
    node *root = tree.create();
    tree.preorder(root);
    cout << endl;
    cout << "The diameter of the binary tree is: " << tree.diameter(root) << endl;
    return 0;
} 