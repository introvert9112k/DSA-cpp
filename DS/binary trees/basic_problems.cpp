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
    void inorder(node *temp)
    {
        if (temp == NULL)
            return;
        inorder(temp->left);
        cout << temp->data << " ";
        inorder(temp->right);
    } 
    int countnodes(node *temp) 
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = countnodes(temp->left);
        y = countnodes(temp->right);
        return x + y + 1;
    }
    int twochilds(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = twochilds(temp->left);
        y = twochilds(temp->right);
        if (temp->left and temp->right)
            return x + y + 1;
        return x + y;
    }

    int onechild(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = onechild(temp->left);
        y = onechild(temp->right);
        if (temp->left != NULL and temp->right == NULL)
            return x + y + 1;
        else if (temp->right != NULL and temp->left == NULL)
            return x + y + 1;
        return x + y;
    } 

    int nochild(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = nochild(temp->left);
        y = nochild(temp->right);
        if (!temp->left and !temp->right)
            return x + y + 1;
        return x + y;
    }
    int height(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = height(temp->left);
        y = height(temp->right);
        return max(x, y) + 1;
    } 
    int sum(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = sum(temp->left);
        y = sum(temp->right);
        return x + y + temp->data;
    }
}; 
int main()

{
    binarytree tree;
    node *root = tree.create();
    cout << "inorder traversal of the tree is : " << endl;
    tree.inorder(root);
    cout << endl;
    cout << "No of nodes in the tree are : " << tree.countnodes(root) << endl;
    cout << "no of nodes with two childs are : " << tree.twochilds(root) << endl;
    cout << "no of nodes with one child are : " << tree.onechild(root) << endl;
    cout << "no of nodes with no childs are : " << tree.nochild(root) << endl;
    cout << "sum of all the nodes in the tree is : " << tree.sum(root) << endl;
    cout << "the height of the tree is : " << tree.height(root) << endl;
    return 0;
}