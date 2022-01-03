// in this we will discuss the level order traversal of the binary tree
#include <bits/stdc++.h>
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
    // matrix for storing the values level by level
    vector<vector<int>> ans;
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
    // level order traversal output in the form of row
    void level_order(node *temp)
    {
        deque<node *> q;
        q.push_back(temp);
        cout << temp->data << " ";
        while (!q.empty())
        {
            temp = q.front();
            q.pop_front();
            if (temp->left != NULL)
            {
                cout << temp->left->data << " ";
                q.push_back(temp->left);
            }
            if (temp->right != NULL)
            {
                cout << temp->right->data << " ";
                q.push_back(temp->right);
            }
        }
    }
    // printing the nodes level by level
    void levelorder(node *root)
    {
        deque<node *> deque;
        // deque for stroing the nodes
        // intially push the root into deque
        deque.push_back(root);
        // iterate until the deque is not empty
        while (!deque.empty())
        {
            // vector level for storing the values in the current level
            vector<int> level;
            // for each iteration obtain the size of the deque
            int size = deque.size();
            for (int i = 0; i < size; i++)
            {
                node *temp = deque.front();
                deque.pop_front();
                if (temp->left)
                    deque.push_back(temp->left);
                if (temp->right)
                    deque.push_back(temp->right);
                level.push_back(temp->data);
            }
            ans.push_back(level);
        }
        return ans;
        // reference : strivers tree's playlist
    }
    // ---------Dfs Approach---------
    void dfs(Node *root, int depth)
    {
        if (root == nullptr)
            return;
        if (ans.size() == depth)
            ans.push_back(vector<int>());
        ans[depth].push_back(root->val);
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    //    code for finding the total no of nodes in tree
    int countnodes(node *temp)
    {
        int x, y;
        if (temp == NULL)
            return 0;
        x = countnodes(temp->left);
        y = countnodes(temp->right);
        return x + y + 1;
    }
};

int main()
{
    binarytree tree;
    node *root = tree.create();
    cout << "level order traversal of the tree is : " << endl;
    // tree.level_order(root);
    tree.levelorder(root);
    // ------for dfs--------
    // tree.dfs(root, 0);
    for (auto vect : tree.ans)
    {
        for (auto val : vect)
            cout << val << " ";
        cout << endl;
    }
}
 