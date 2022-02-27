#include <bits/stdc++.h>
using namespace std;
// Explanation
// dp[i] stores the maximum length of the increasing subsequences that will end at the ith index

int lis(vector<int> &arr, vector<int> &dp)
{
    // pepcoding channel
    int n = arr.size();
    int maxlen = 0;
    // to keep track of the maxlength of the increasing subsequence found till now

    // iterating over the all indexes
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        // to keep track of the max value found in the dp array from 0 to i-1
        for (int j = 0; j < i; j++)
        {
            // if the arr[i] is greater than the arr[j] then arr[i] can be added into that subsequence
            // if you use >= we will get largest non -decreasing subsequence. if use > then we will get largest increasing subsequence
            if (arr[i] > arr[j])
                //    finding maximum of the such subsequences
                mx = max(mx, dp[j]);
        }
        // now the maximum length of the increasing subsequence is 1 greater than the max length found
        // because we are adding this element to that subsequence,if no sequence found then the 1 is max lis
        dp[i] = mx + 1;
        maxlen = max(dp[i], maxlen);
    }

    // ---------code for finding out the one of the such lis -----------
    cout << "one of possible largest increasing subsequence is " << endl;
    int key = maxlen;
    // define a vector of lenth lis
    vector<int> sequence(maxlen);
    // iterate from backwards in dp array,and findout the value which is equal to maxlen then add coresponding value in arr to subsequence vector at last
    // next decrease the value by 1 to find out the next element in lis from backwards
    for (int k = n - 1; k >= 0; k--)
    {
        if (dp[k] == key)
            sequence[--key] = arr[k];
    }
    for (auto &val : sequence)
        cout << val << " ";
    cout << endl;
    return maxlen;
    // Time complexity --- O(N^2)
    // space Complexity --- O(N)
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    vector<int> dp(n, 0);
    int len = lis(arr, dp);
    cout << "length of the longest increasing subsequence is " << len << endl;
    return 0;
} 