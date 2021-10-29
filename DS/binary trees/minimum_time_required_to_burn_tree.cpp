// problem statement
// Fire is lit at one node in binary tree,we should find the time taken to burn the whole tree,given time taken to burn the adjacent nodes for given node is 1 sec
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
    Node *makeparents(Node *root, unordered_map<Node *, Node *> &parent, int target)
    {
        queue<Node *> q;
        q.push(root);
        Node *target_node;
        while (!q.empty())
        {
            Node *curr = q.front();
            q.pop();
            if (curr->data == target)
                target_node = curr;
            if (curr->left)
            {
                parent[curr->left] = curr;
                q.push(curr->left);
            }
            if (curr->right)
            {
                parent[curr->right] = curr;
                q.push(curr->right);
            }
        }
        return target_node;
    }
    int burningtime(Node *root, int target)
    {
        unordered_map<Node *, Node *> parent;
        Node *target_node = makeparents(root, parent, target);
        unordered_map<Node *, bool> burnt;
        queue<Node *> q;
        q.push(target_node);
        burnt[target_node] = true;
        int burntime = 0;
        while (!q.empty())
        {
            int size = q.size();
            bool burn = false;
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left and !burnt[curr->left])
                {
                    burn = true;
                    q.push(curr->left);
                    burnt[curr->left] = true;
                }
                if (curr->right and !burnt[curr->right])
                {
                    burn = true;
                    q.push(curr->right);
                    burnt[curr->right] = true;
                }
                if (parent[curr] and !burnt[parent[curr]])
                {
                    burn = true;
                    q.push(parent[curr]);
                    burnt[parent[curr]] = true;
                }
            }
            if (burn)
                burntime++;
        }
        return burntime;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int target;
    cout << "enter the target" << endl;
    cin >> target;
    int time = tree.burningtime(root, target);
    cout << time << endl;
} 