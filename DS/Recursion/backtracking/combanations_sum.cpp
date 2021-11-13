#include <bits/stdc++.h>
using namespace std;
// problem statement
// Given an array of distinct integers candidates and a target integer target, return a list of all unique combinations of candidates where the chosen numbers sum to target. You may return the combinations in any order.

// The same number may be chosen from candidates an unlimited number of times. Two combinations are unique if the frequency of at least one of the chosen numbers is different.

void combinations(int index, vector<int> &arr, vector<int> &ds, int target)
{

    // base case
    // whenever we reach the last index or target is zero we are done.
    if (index == arr.size() or target == 0)
    {
        if (target == 0)
        {
            for (auto val : ds)
                cout << val << " ";
            cout << endl;
        }
        return;
    }
    // for every index we have two options whether we choose or we not choose
    // As the number can be taken unlimited times we take the number until the target is less than the current number ,after that we move to next number

    // Make sure to remove the elements inserted into ds after the left call is finished
    if (arr[index] <= target) // include only when the arr[index] <= target
    {
        ds.push_back(arr[index]);                          // pushing the value in to ds
        combinations(index, arr, ds, target - arr[index]); // calling the function with same index and changing the target value
        ds.pop_back();                                     // popping the element after the call considering the element is finished
    }
    combinations(index + 1, arr, ds, target); // call for not considering the element
} 
// Time complexity ---- O(2^target x k)
// k is the average length of the all the combinations ,because we are printing the combination which would take O(length of combination) 
// So we cannot predict the length of each combination so we take the average value

// leetcod  :https://leetcode.com/problems/combination-sum/
int main()

{
    int n, target;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "Enter the target" << endl;
    cin >> target;
    vector<int> ds;
    combinations(0, arr, ds, target);
    return 0;
} 