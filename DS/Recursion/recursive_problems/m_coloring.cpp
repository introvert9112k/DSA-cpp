#include <bits/stdc++.h>
using namespace std;
// source : strivers recurison playlist
// Time Complexity : O(m^n)
// Space Complexity : O(N)
bool ispossible(int node, bool graph[101][101], vector<int> &color, int m, int n, int col)
{
    for (int i = 0; i < n; i++) /*checking whehter any adjacent node has same color*/
    {
        if (i != node && graph[node][i] == 1 && color[i] == col)
            return false;
    }
    return true;
}
bool solve(int node, bool graph[101][101], vector<int> &color, int m, int n)
{
    if (node == n) /*If we reach the last node, we got a valid coloring*/
        return true;
    for (int col = 1; col <= m; col++) /*Trying out all the colors for the node*/
    {
        if (ispossible(node, graph, color, m, n, col)) /*Checking whether it is possible to color the node,with current color*/

        {
            color[node] = col; // assigning the color to node.
            if (solve(node + 1, graph, color, m, n))
                return true; // Calling for another node.
            color[node] = 0; // Uncoloring the node.
        }
    }
    return false; /*If any color cannot used for the node, then return false*/
}
bool graphColoring(bool graph[101][101], int m, int n)
{
    // your code here
    vector<int> color(n, 0); /*vector for storing the present color of the nodes*/
    if (solve(0, graph, color, m, n))
        return true;
    return false;
}
int main()

{

    return 0;
}  