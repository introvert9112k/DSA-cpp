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
    vector<vector<int>> zigzag(Node *root)
    {
        deque<Node *> deque;
        int flag = 0;
        vector<vector<int>> ans;
        deque.push_back(root);
        while (!deque.empty())
        {
            int size = deque.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++)
            {
                Node *temp = deque.front();
                deque.pop_front();
                if (temp->left)
                    deque.push_back(temp->left);
                if (temp->right)
                    deque.push_back(temp->right);
                flag & 1 ? level[size - i - 1] = temp->data : level[i] = temp->data;
            }
            ans.push_back(level);
            flag++;
        }
        return ans;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<vector<int>> ans = tree.zigzag(root);
    for (auto vect : ans)
    {
        for (auto x : vect)
            cout << x << " ";
        cout << endl;
    }
}