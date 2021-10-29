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
    Node *findnode(Node *temp, int target)
    {
        if (!temp)
            return NULL;
        if (temp->data == target)
            return temp;
        Node *l = findnode(temp->left, target);
        if (l)
            return l;
        Node *r = findnode(temp->right, target);
        if (r)
            return r;
        return NULL;
    }
    void makeparents(Node *root, unordered_map<Node *, Node *> &parent)
    {
        queue<Node *> queue;
        queue.push(root);
        while (!queue.empty())
        {
            Node *temp = queue.front();
            queue.pop();
            if (temp->left)
            {
                parent[temp->left] = temp;
                queue.push(temp->left);
            }
            if (temp->right)
            {
                parent[temp->right] = temp;
                queue.push(temp->right);
            }
        }
    }
    vector<int> Nodesatdistancek(Node *root, int target, int k)
    {
        // if the address of the target node is not given ,find the address and proceed
        Node *address = findnode(root, target);
        unordered_map<Node *, Node *> parent;
        makeparents(root, parent);
        unordered_map<Node *, bool> visited;
        queue<Node *> queue;
        queue.push(address);
        visited[address] = true;
        int dis = 0;
        while (!queue.empty())
        {
            int size = queue.size();
            if (dis == k)
                break;
            dis++;
            for (int i = 0; i < size; i++)
            {
                Node *curr = queue.front();
                queue.pop();
                if (curr->left and !visited[curr->left])
                {
                    queue.push(curr->left);
                    visited[curr->left] = true;
                }
                if (curr->right and !visited[curr->right])
                {
                    queue.push(curr->right);
                    visited[curr->right] = true;
                }
                if (parent[curr] and !visited[parent[curr]])
                {
                    queue.push(parent[curr]);
                    visited[parent[curr]] = true;
                }
            }
        }
        vector<int> ans;
        while (!queue.empty())
        {
            ans.push_back(queue.front()->data);
            queue.pop();
        }
        return ans;
    }
    // strivers playlist
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    int target, k;
    cout << "enter the target" << endl;
    cin >> target;
    cout << "enter the distance" << endl;
    cin >> k;
    vector<int> ans = tree.Nodesatdistancek(root, target, k);
    for (auto val : ans)
        cout << val << " ";
} 