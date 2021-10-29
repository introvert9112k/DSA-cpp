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
    vector<int> bottomview(Node *root)
    {
        // store the node and the vertical line number in the deque
        deque<pair<Node *, int>> deque;
        // map is for mapping the line number and the first appeared element in that line
        // last appeared elements in all lines are the bottomview of the tree
        // as the lines are numbered,use only map so that the pairs are stored in sorted order i.e line -1,0,1 etc
        map<int, int> map;
        vector<int> ans;
        // Intially push the root and vertical line on which root is present i.e 0
        deque.push_back({root, 0});
        while (!deque.empty())
        {
            auto it = deque.front();
            deque.pop_front();
            Node *temp = it.first;
            int line = it.second;
            // updating the value of line wheneever we encounter the node in that line
            map[line] = temp->data;
            // if the left child exists,push the temp->left and line-1 into deque,because as we move on left line decreases by 1 and level increases by 1
            if (temp->left)
                deque.push_back({temp->left, line - 1});
            // if the right child exists,push the temp->right and line+1 into deque,because as we move on right line increases by 1 and level increases by 1
            if (temp->right)
                deque.push_back({temp->right, line + 1});
        }
        // After the iteration map contains the line and last element in that line
        // so iterate through map and store the line values into vector
        for (auto it : map)
            ans.push_back(it.second);
        return ans;
    }
};

int main()
{
    binarytree tree;
    Node *root = tree.construct();
    vector<int> ans = tree.bottomview(root);
    for (auto x : ans)
        cout << x << " ";
}  