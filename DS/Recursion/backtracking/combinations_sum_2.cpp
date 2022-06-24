#include <bits/stdc++.h>
using namespace std;
typedef vector<int> vi;
typedef vector<vector<int>> vii;

// Question : https : // leetcode.com/problems/combination-sum-ii/
// Solution : Strivers recursion playlist
// ------------------------Brute Force----------------
// Find the all the combinations and add them into set which will store only the unique combinations
// Time Complexity : O(2^n * Klogn)
// 2^n for finding the combinations, k for inserting ds elements into set, logn for checking the duplicateness
// ----------------------------Brute Force end--------------------

void combinations_sum2(int ind, int target, vi &arr, vii &ans, vi &ds)
{
    if (target == 0) /*for loop take cares of the ind == n condition.*/
    {
        ans.push_back(ds);
        return;
    }
    for (int i = ind; i < arr.size(); i++) /*This is another type of pattern in recursion*/
    {
        /*If previous value and current value are equal don't pick up, because they will end up in  getting duplicates*/
        if (i > ind && arr[i] == arr[i - 1])
            continue;
        /*As the array is sorted,if we cannot pick a value then all the further values also cannot be picked,so return there itself*/
        if (arr[i] > target)
            return;
        ds.push_back(arr[i]);
        combinations_sum2(i + 1, target - arr[i], arr, ans, ds);
        ds.pop_back();
    }
}

void combinationSum2(vector<int> &candidates, int target)
{
    sort(candidates.begin(), candidates.end()); /*sorting helps to identify the duplicate combinations*/
    vector<vector<int>> ans;                    /*for storing all the combinations*/
    vector<int> ds;                             /*for storing current combination*/
    combinations_sum2(0, target, candidates, ans, ds);
    cout << "all the combinations whose sum is equal to " << target << " is " << endl;
    for (auto &vect : ans)
    {
        for (auto &val : vect)
            cout << val << " ";
        cout << endl;
    }
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    combinationSum2(arr, target);
} 