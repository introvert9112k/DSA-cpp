#include <iostream>
#include <string>
#include <algorithm>
// constructing the binary search tree

// properties of bst
// 1.it does not contain duplicates
// 2.inorder traversal of the bst is sorted

using namespace std;
class node
{
public:
  node *left;
  int data;
  node *right;
};
node *root = NULL;
// root pointer for acessing globally
class binarytree
{
public:
  // function to construct the bst,in this we are taking one by one element and inserting it in correct positon in bst
  void create(int value)
  {
    // previous pointer points to parent node to which we want to make a child,and current pointer is for finding that parent node
    node *previous, *current = root;
    // if current is null,it means inserting value should go into root node,so create a node and make it as root
    if (current == NULL)
    {
      node *new_node = new node;
      new_node->data = value;
      new_node->left = new_node->right = NULL;
      root = new_node;
      return;
    }
    // if inserting value is not corresponding to root node,then check for parent node in the bst
    // iterate until the null pointer,the node to which the null pointer is child will be the parent node for the value
    while (current)
    {
      previous = current;
      // storing the previous node value into the previous pointer,in each iteration,in the last iteration the
      // node in previous pointer will be the parent node for the value

      // if the value is less than the current node data, then value should be at left side of current node,so make current to current->left for checking the left side of current node/
      if (value < current->data)
        current = current->left;
      // similarly for the right side too
      else if (value > current->data)
        current = current->right;
      // if the value is equal to some node,in the bst,that mean we are inserting duplicates ,as bst does not contain duplicates, stop the function excution/
      else
        return;
    }
    // After the iteration, current will be null and previous will be pointing to the parent node

    // create a new node for the value
    node *new_node = new node;
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    // here we knew the parent node,but to whcih side we should connect the value,so if value is less than the nodes data then the value should be left child of the node,else right child
    if (value < previous->data)
      previous->left = new_node;
    else
      previous->right = new_node;
  }

  // this is recursive way to create a binary search tree
  node *rcreate(int value, node *current = root)
  {
    if (current == NULL)
    {
      node *new_node = new node;
      new_node->data = value;
      new_node->right = new_node->left = NULL;
      if (root == NULL)
        root = new_node;
      return new_node;
    }
    else if (value < current->data)
      current->left = rcreate(value, current->left);
    else if (value > current->data)
      current->right = rcreate(value, current->right);
    return current;
  }

  // this is same as we discussed int the create function,first find the parent node,check for right or left child and insert it
  void insert(int value)
  {
    node *previous, *current = root;
    while (current)
    {
      previous = current;
      if (value < current->data)
        current = current->left;
      else if (value > current->data)
        current = current->right;
      else
        return;
    }
    node *new_node = new node;
    new_node->data = value;
    new_node->left = new_node->right = NULL;
    if (value < previous->data)
      previous->left = new_node;
    else
      previous->right = new_node;
  }
  // searching for the element in bst
  // if the key is equal to the current node value then return true,
  // if key value is less than the current node value then check in left sub tree ,else check in the right sub tree
  // if no node found then return false
  bool search(int key)
  {
    node *temp = root;
    while (temp)
    {
      if (temp->data == key)
        return true;
      else if (key < temp->data)
        temp = temp->left;
      else
        temp = temp->right;
    }
    return false;
  }

  // this is the recursive way to search
  bool rsearch(int key, node *temp = root)
  {
    if (temp == NULL) //case where the value is not present in bst
      return false;
    else if (key == temp->data)
      return true;
    else if (key < temp->data)
      return rsearch(key, temp->left);
    else
      return rsearch(key, temp->right);
  }

  void inorder(node *temp)
  {
    if (temp == NULL)
      return;
    inorder(temp->left);
    cout << temp->data << " ";
    inorder(temp->right);
  }
  node *check(node *current, node *checking)
  {
    if (checking->data < current->data)
      return current->left;
    else if(checking->data > current->data)
       return current->right;
    else
      return current;
  }
  int lowest(node *node1, node *node2, node *root)
  {
    node *current1 = root, *current2 = root;
    current1 = check(current1, node1);
    current2 = check(current2, node2);
    node *ans = root;
    // if (current1->data == node1->data)
    //   return current1;
    // if (current2->data == node2->data)
    //   return current2;
    while ((current1->data != node1->data) or (current2->data != node2->data))
    {
      if (current1->data == current2->data)
      {
        ans = current1;
        current1 = check(current1, node1);
        current2 = check(current2, node2);
      }
      else
      {
        if (current1->data < current2->data)
          current1 = check(current1, node1);
        else
          current2 = check(current2, node2);
      }
    }
    return ans->data;
  }
};
int main()
{
  binarytree tree;
  int x;
  cin >> x;

  while (x != -1)
  {
    tree.rcreate(x);
    cin >> x;
  }
  cout << endl;
  tree.inorder(root);
  cout << endl;
  // tree.insert(99);
  // tree.insert(3);
  // tree.insert(0);
  // cout << endl;
  // tree.inorder(root);
  // cout << endl;
  cout << tree.rsearch(2) << endl;
  cout << tree.rsearch(8) << endl;

  return 0;
}
