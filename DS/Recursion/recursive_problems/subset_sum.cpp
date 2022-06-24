#include <bits/stdc++.h>
using namespace std;

// problem statement
// Give the sum of all the subsets in the increasing order

// Theory :
// No of subsets for n elements array is 2^n
// subsets and subsequences are equal only difference is that subsequence follow the same order in array whereas subset need not to follow any order
// Subsets are nothing but the subsequences

// Method1 : using Powerset
// Time Complexity : O(2^N x N)
// 2^n for the loop, and in each iteration we are iterating through the binary number of the number
// Space Complexity : O(2^N)
// vector has 2^N elements because,no of subsets is 2^N
void power_set(int n, vector<int> &arr, vector<int> &subsets)
{
    for (int i = 0; i < pow(2, n); i++)
    {
        int num = i, sum = 0;
        while (num > 0)
        {
            int rsbm = num & -num;
            sum += arr[log2(rsbm)];
            num -= rsbm;
        }
        subsets.push_back(sum);
    }
}
// Time Complexity : O(2^N + 2^Nlog(2^N))
// 2^N for finding subsequences and 2^Nlog(2^n) for sorting the vecto
// Space Complexity : O(2^N)
// vector has 2^N elements because,no of subsets is 2^N
void subset_sum(int i, int n, int sum, vector<int> &arr, vector<int> &subsets)
{
    if (i == n)
    {
        subsets.push_back(sum);
        return;
    }
    subset_sum(i + 1, n, sum + arr[i], arr, subsets);
    subset_sum(i + 1, n, sum, arr, subsets);
}
int main()
{
    int n;
    cin >> n;
    vector<int> arr(n), subsets;
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    power_set(n, arr, subsets);
    sort(subsets.begin(), subsets.end());
    cout << "Sum of all the subsets in ascending order is  : " << endl;
    for (auto &val : subsets)
        cout << val << " ";
    cout << endl;
    return 0;
} 