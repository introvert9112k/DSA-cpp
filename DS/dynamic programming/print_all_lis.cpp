#include <bits/stdc++.h>
using namespace std;
// code to print all the lis in the array
// pepcoding youtube channel

class sequence
{
public:
    int length;
    int index;
    int value;
    string strsofar;
    sequence(int _l, int _i, int _val, string _str)
    {
        length = _l;
        index = _i;
        value = _val;
        strsofar = _str;
    }
};
int findmaxlenlis(vector<int> &arr, vector<int> &dp)
{
    int maxlen = 0, n = arr.size();
    for (int i = 0; i < n; i++)
    {
        int mx = 0;
        for (int j = 0; j < i; j++)
        {
            if (arr[i] >= arr[j])
                mx = max(mx, dp[j]);
        }
        dp[i] = mx + 1;
        maxlen = max(maxlen, dp[i]);
    }
    cout << "maxlength of the increasing subsequence is  : " << maxlen << endl;
    return maxlen;
}
void print_all_lis(vector<int> &arr, vector<int> &dp, int maxlen)
{
    queue<sequence> q;
    for (int i = 0; i < arr.size(); i++)
    {
        if (dp[i] == maxlen)
        {
            q.push(sequence(maxlen, i, arr[i], to_string(arr[i]) + " "));
        }
    }
    while (!q.empty())
    {
        sequence curr = q.front();
        q.pop();
        if (curr.length == 1)
        {
            cout << curr.strsofar << endl;
        }
        for (int i = 0; i < curr.index; i++)
        {
            if (dp[i] == curr.length - 1 && arr[i] <= arr[curr.index])
                q.push(sequence(dp[i], i, arr[i], to_string(arr[i]) + " " + curr.strsofar));
        }
    }
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n), dp(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    print_all_lis(arr, dp, findmaxlenlis(arr, dp));

    return 0;
} 