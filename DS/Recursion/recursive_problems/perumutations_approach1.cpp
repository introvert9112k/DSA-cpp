#include <bits/stdc++.h>
using namespace std;
/* ------------Problem statement------------
Given an array of distnict integers find all its permutaions.
NOTE : If the array elements are not unique then there will be duplicate permutations
*/

/*There are n! permuations possible.
Source : stivers playlist.
Time complexity : O(n! x n)
n! for finding the permutaions, n for printing the permutation
Space Complexity : O(n) + O(n)
Space for the vectors ds and visited.
Auxilary Space : O(n)
Atmost n recursion calls can wait in stack.

Intuition : 
1. We are making sure that the every element in the array should present
in every index combined in all permutations.
*/
void permutations(int n, vector<int> &arr, vector<int> &ds, vector<int> &visited)
{
    /*When we reach the last index of the permutation*/
    if (ds.size() == n)
    {
        for (auto &val : ds)
            cout << val << " ";
        cout << endl;
    }
    /*Suppose we are at index i,then this index can have all the numbers
    which doesn't appear in this permutation at places [0,i-1].
    We are running a for loop and checking whether the current number can 
    be placed at this position or not.
    */
    for (int i = 0; i < n; i++)
    {  
        /*Visited i says which numbers are already included in current 
        permutation*/
        if (visited[i] == 0)
        {
            ds.push_back(arr[i]);
            visited[i] = 1;
            permutations(n, arr, ds, visited);
            ds.pop_back();
            visited[i] = 0;
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ds, visited(n, 0);
    cout << "All the permutations are : " << endl;
    permutations(n, arr, ds, visited);
    return 0;
} 