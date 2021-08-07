// in this we will discuss the level order traversal of the binary tree
#include<bits/stdc++.h>
using namespace std;
class node
{  
    public:
    node *left;
    int data;
    node *right; 
};
class binarytree{
    public:
   node* create()
   {
       int x;
       static int i = 0;
       if(i==0)
       {
           cout << "Enter the root node value" << endl;
           i++;
       }
       cin >> x;
       if(x==-1)
           return NULL;
       node *new_node = new node;
       new_node->data = x;
       new_node->right = new_node->left = NULL;
       cout << "Enter the left child of the node " << new_node->data << endl;
       new_node->left = create();
       cout << "Enter the right child of the node " << new_node->data << endl;
       new_node->right = create();
       return new_node;
   }

   void level_order(node * temp)
   {
       deque<node *> q;
       q.push_back(temp);
       cout << temp->data << " ";
       while(!q.empty())
       {
           temp = q.front();
           q.pop_front();
           if(temp->left!=NULL)
           {
               cout << temp->left->data << " ";
               q.push_back(temp->left);
           }
           if(temp->right!=NULL)
           {
               cout << temp->right->data << " ";
               q.push_back(temp->right);
           } 
       }
   } 
//    code for finding the total no of nodes in tree
   int countnodes(node* temp)
   {
       int x, y;
       if(temp==NULL)
           return 0;
       x = countnodes(temp->left);
       y = countnodes(temp->right);
       return x + y+ 1;
   } 
}; 

int main() 
{
    binarytree tree;
    node *root = tree.create();
    cout << "level order traversal of the tree is : " << endl;
    tree.level_order(root);
    cout << "\n no of nodes in tree is : " << tree.countnodes(root) << endl;
} 