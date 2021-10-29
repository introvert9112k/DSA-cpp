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
    string serialize(Node *root)
    {
        queue<Node *> q;
        q.push(root);
        string ans;
        ans.push_back(char(48 + root->data));
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->left)
            {
                q.push(curr->left);
                ans.push_back(char(48 + curr->left->data));
            }
            if (curr->right)
            {
                q.push(curr->right);
                ans.push_back(char(48 + curr->right->data));
            }
            if (!curr->left)
                ans.push_back('#');
            if (!curr->right)
                ans.push_back('#');
        }
        return ans;
    }
    Node *deseriliaze(string s)
    {
        queue<Node *> q;
        Node *root = new Node(int(s[0] - 48));
        q.push(root);
        int i = 1;
        int n = s.length();
        while (i < n)
        {
            Node *curr = q.front();
            q.pop();
            if (s[i] != '#')
            {
                curr->left = new Node(int(s[i] - 48));
                q.push(curr->left);
                i++;
            }
            else
            {
                curr->left = NULL;
                i++;
            }
            if (s[i] != '#')
            {
                curr->right = new Node(int(s[i] - 48));
                q.push(curr->right);
                i++;
            }
            else
            {
                curr->right = NULL;
                i++;
            }
        }
        return root;
    }
};
void preorder(Node *root1)
{
    if (!root1)
        return;
    cout << root1->data << " ";
    preorder(root1->left);
    preorder(root1->right);
}
int main()
{
    binarytree tree;
    Node *root = tree.construct();
    string s = tree.serialize(root);
    cout << "serialisation is " << s << endl;
    Node *root1 = tree.deseriliaze(s);
    preorder(root1);
}      