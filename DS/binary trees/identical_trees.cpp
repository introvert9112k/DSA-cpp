#include <bits/stdc++.h>
using namespace std;

class Node
{
public:
    int data;
    Node *left;
    Node *right;
    Node(int x)
    {
        data = x;
        left = right = NULL;
    }
};
class binarytree
{
public:
    Node *construct()
    {
        int x;
        cout << "Enter the data" << endl;
        cin >> x;
        if (x == -1)
            return NULL;
        Node *temp = new Node(x);
        cout << "Enter the left child of the node  " << temp->data << endl;
        temp->left = construct();
        cout << "Enter the right child of the node " << temp->data << endl;
        temp->right = construct();
        return temp;
    }
    void preorder(Node *temp)
    {
        if (!temp)
            return;
        cout << temp->data << " ";
        preorder(temp->left);
        preorder(temp->right);
    }
};
bool isidentical(Node *temp1, Node *temp2)
{
    // we should simultaneously traverse the both the trees and should check whether the nodes data and postiton of nodes in trees

    // if any of the node in the trees is null,if the node in other tree is also then return true else return false
    if (!temp1 or !temp2)
        return temp1 == temp2;
    // checking the nodes data value in two trees,if not equal return false
    if (temp1->data != temp2->data)
        return false;
    // simultaneously iterating the two trees
    // if any of the node in tree return false then return false else return true
    if (!isidentical(temp1->left, temp2->left) or !isidentical(temp1->right, temp2->right))
        return false;
    return true;
    // check strivers playlist for better explanation
}
bool isidentical1(Node *temp1, Node *temp2)
{
    if (!temp1 or !temp2)
        return temp1 == temp2;
    if (temp1->data != temp2->data)
        return false;
    return isidentical(temp1->left, temp2->left) and isidentical(temp1->right, temp2->right);
}
int main()
{
    binarytree tree1, tree2;
    cout << "construct tree1" << endl;
    Node *root1 = tree1.construct();
    cout << "Costruct tree2 " << endl;
    Node *root2 = tree2.construct();
    isidentical(root1, root2) ? (cout << "balanced") : (cout << "unbalcanced");
    cout << endl;
    isidentical1(root1, root2) ? (cout << "balanced") : (cout << "unbalcanced");
    return 0;
} 