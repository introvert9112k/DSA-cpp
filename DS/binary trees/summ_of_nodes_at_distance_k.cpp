// problem statement
// given a binary tree,find the sum of the all the nodes which
// are at the maximum distance of k
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
    Node *makeparents(Node *curr, unordered_map<Node *, Node *> &parent, int target)
    {
        queue<Node *> q;
        q.push(curr);
        Node *target_node;
        while (!q.empty())
        {
            Node *temp = q.front();
            if (temp->data == target)
                target_node = temp;
            q.pop();
            if (temp->left)
            {
                q.push(temp->left);
                parent[temp->left] = temp;
            }
            if (temp->right)
            {
                q.push(temp->right);
                parent[temp->right] = temp;
            }
        }
        return target_node;
    }
    int nodes_at_distance_k(Node *root, int k, int target)
    {
        unordered_map<Node *, Node *> parent;
        Node *target_node = makeparents(root, parent, target);
        unordered_map<Node *, bool> visited;
        int d = 0;
        int sum = 0;
        queue<Node *> q;
        visited[target_node] = true;
        q.push(target_node);
        while (d <= k)
        {
            int size = q.size();
            for (int i = 0; i < size; i++)
            {
                Node *curr = q.front();
                q.pop();
                if (curr->left and !visited[curr->left])
                {
                    q.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right and !visited[curr->right])
                {
                    q.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] and !visited[parent[curr]])
                {
                    q.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
                cout << curr->data << " ";
                sum += curr->data;
            }
            d++;
        }
        return sum;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int k, target;
    cout << "enter the target value" << endl;
    cin >> target;
    cout << "enter the k value" << endl;
    cin >> k;
    cout << endl;
    cout << tree.nodes_at_distance_k(root, k, target) << endl;
}
