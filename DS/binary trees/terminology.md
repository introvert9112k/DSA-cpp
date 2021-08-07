Trees

**NOde** - Every element in the trees is called node.

**Root** - The first node of the tree,or node which does not have parent node is called root node

**parent NOde** - The node which is immediate predecessor of the given node is called parent node of that node

**child Node** - The node which is immediate succesor of the given node is called child node of the current node

**leaf NOde** - The node which does not have any childs is called leaf node

**NOn leaf NOde** - The nodes which has atleast one child node is called non leaf node

**edges** - the link joining the two nodes is called edge

**path** - The sequence of the consecutive edges from the source node to destination node is called path

**depth of the node** - No of edges along the path from the root node to that node

**height of the node** - maximum NO of edges along the path from the current node to the leaf node.

height of the leaf node is zero. height of the tree is equal to the height of the root node

**level of the node** - no of edges along the path from root to that node.level is equal to the depth of the node.
level of tree is equal to the height of the tree or height of the root node.

**NOTE** - height and depth of the node may or may not equal

**sliblings** - Nodes having same parent are called siblings

**degree of node** - degree of node is equal to the no of childs does node has

**degree of the tree** - degree of tree is maximum degree that a node in tree has

**ancestor** - nodes which are along the path from the root node to the current node excluding the current node are called ancestors of the current node

**decendent** - Nodes whcih are along the path form the current node to the leaf node are called the decendents of the current node.

**subtree** - A node and all its decendents form a sub tree

**if tree has N nodes then it should have n-1 edges.**

**binary tree is the tree in which all the nodes has atmost 2 nodes ,that mean each node has 0,1,2 child nodes**

**BInary trees**
The tree in which every node has atmost 2 children ,then tree is known as binary tree

**Formulas for binary trees**
Given n unlablled nodes,then the number of binary trees can be formed by these nodes is given by formula 
 2nCn/(n+1) 
Among these binary trees, the trees with maximum height is 2**n-1 - 1(2 power n-1 and minus 1)

given n nodes which are labelled then no of trees formed would be (2nCn/n+1)*n!
Trees with maximum height are (2**n-1 - 1)*n! 

Given the height of binary tree is h,then minumum nodes required for having height h is h+1
  min nodes for having height h is **n = h+1**
  max nodes for having height h is  n = 2**h+1 -1 (2 power h+1 minus 1) 

Given n nodes then the maximum and minmum height trees that can be formed by these nodes are given by
  max height of tree is **h = n -1** 
  min height of the tree is **h = log2(n+1) - 1**

  so range of h is from   **log2(n+1) - 1 <= h <= n-1**

**Relation between internal and external nodes**
  no of nodes with degree zero = no of nodes with degree 2 + 1
  deg(0) = deg(2) +1

**Strict binary tree**
binary tree in which the each node has either 0 or 2 nodes,is called strict binary tree

**Formulas for strict binary tree** 

Given the height of binary tree is h,then minumum nodes required for having height h is h+1
  min nodes for having height h is **n = 2*h+1**
  max nodes for having height h is  n = 2**h+1 -1 (2 power h+1 minus 1) 

given n nodes the minimum and maximum height is 
  minimum height **h = log2(n+1) - 1**
  maximum heigt **h = (n-1)/2**

**Relation between internal and external nodes for strict binary trees**
  no of nodes with degree zero = no of nodes with degree 2 + 1
  deg(0) = deg(2) +1 