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
        Node *new_node = new Node(x);
        cout << "Enter the left child of the node " << new_node->data << endl;
        new_node->left = construct();
        cout << "Enter the right child of the node " << new_node->data << endl;
        new_node->right = construct();
        return new_node;
    }
    // if the both n1 and n2 are present this will return the lca of n1 and n2 if none of them present it returns -1
    // we can also return the lca node instead of value also,return node instead of -1 and values
    int lca(Node *temp, int n1, int n2)
    {
        if (!temp)
            return -1;
        if (temp->data == n1 or temp->data == n2)
            return temp->data;
        int l = lca(temp->left, n1, n2);
        int r = lca(temp->right, n1, n2);
        if (l != -1 and r == -1)
            return l;
        else if (l == -1 and r != -1)
            return r;
        else if (l != -1 and r != -1)
            return temp->data;
        else
            return -1;
    }
    // strivers playlist
    Node *lca1(Node *temp, int n1, int n2)
    {
        if (!temp)
            return NULL;
        if (temp->data == n1 or temp->data == n2)
            return temp;
        Node *left = lca1(temp->left, n1, n2);
        Node *right = lca1(temp->right, n1, n2);
        if (left and !right)
            return left;
        if (!left and right)
            return right;
        if (left and right)
            return temp;
        return NULL;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int n1, n2;
    cout << "Enter the two values" << endl;
    cin >> n1 >> n2;
    int ans = tree.lca(root, n1, n2);
    ans != -1 ? cout << "lca is " << ans << endl : cout << "no lca" << endl;

    Node *res = tree.lca1(root, n1, n2);
    res ? cout << "lca is " << res->data << endl : cout << "no lca " << endl;
} 