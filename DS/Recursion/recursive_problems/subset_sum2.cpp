#include <bits/stdc++.h>
using namespace std;
// problem statement
// Given a integer array which may contain duplicates, find the all unique subsets

// ----------Brute Force------------
// 1.Generate all the subsets, put them into set and print the subsets in set
// Time Complexity : O(2^n + 2^nlog(2^n))  2^n for finding the subset, and 2^nlog(2^n) for inserting into set
// Space Complexity : O(2^n *k ) no of subsets are 2^n and each subset has an average size of k
void subsets(int i, int n, vector<int> &arr, vector<int> &ds, set<vector<int>> &ans)
{
    if (i == n)
    {
        ans.insert(ds);
        return;
    }
    ds.push_back(arr[i]);            // pick
    subsets(i + 1, n, arr, ds, ans); // move forward
    ds.pop_back();                   // don't pick
    subsets(i + 1, n, arr, ds, ans); // move forward
}

// -----------------Avoiding Duplicates in Recursion only---------------------
// Source : strivers playlist
// In each step of recursion we are finding the unique subsets of that size.
// Time Complexity : O(2^n *n) 2^n for finding the subsets, and let's assume on average size of the each subset is n. Inserting into ans vector takes O(n) time.
// Space Complexity : O(2^n *k ) 2^n subsets and average size of each subset is k
// Auxilary Space : O(n) At most n calls would be waiting in  the stack or Depth of the recursion tree is n
void subset_sum2(int ind, int n, vector<int> &arr, vector<int> &ds, vector<vector<int>> &ans)
{
    ans.push_back(ds);
    if (ind == n)
        return;
    for (int i = ind; i < n; i++)
    {
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        ds.push_back(arr[i]);
        subset_sum2(i + 1, n, arr, ds);
        ds.pop_back();
    }
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> ds;
    set<vector<int>> ans;
    cout << "All the unique subsets are : " << endl;
    subsets(0, n, arr, ds, ans);
    for (auto &vect : ans)
    {
        cout << "[ ";
        for (auto &val : vect)
            cout << val << " ";
        cout << "]" << endl;
    }
    return 0;
}
