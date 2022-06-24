#include <bits/stdc++.h>
using namespace std;

// problem statement
// find out the subsequences whose sum is equal to k

/*------------------ Approach---------------------------
 1.Find the all the subsequences and check whehter their sum is equal to k or not
 2.If sum  == k print the subsequence
*/
void ksum_subsequence1(int i, int n, int sum, int k, vector<int> &arr, vector<int> &temp)
{
    if (i == n)
    {
        if (sum == k)
        {
            for (auto &val : temp)
                cout << val << " ";
            cout << endl;
        }
        return;
    }
    temp.push_back(arr[i]);
    sum += arr[i];
    ksum_subsequence1(i + 1, n, sum, k, arr, temp);
    temp.pop_back();
    sum -= arr[i];
    ksum_subsequence1(i + 1, n, sum, k, arr, temp);
}

// Varitaion
// Print any subsequence whose sum is equal to k
bool ksum_subsequence2(int i, int n, int sum, int k, vector<int> &arr, vector<int> &temp)
{
    if (sum == k)
    {
        for (auto &val : temp)
            cout << val << " ";
        return true;
    }
    if (i == n)
        return false;
    temp.push_back(arr[i]);
    sum += arr[i];
    if (ksum_subsequence2(i + 1, n, sum, k, arr, temp))
        return true;
    temp.pop_back();
    sum -= arr[i];
    if (ksum_subsequence2(i + 1, n, sum, k, arr, temp))
        return true;
    return false;
}
// Another variaton
// Count the subsequences with sum k
void cnt_subsequences(int i, int n, int sum, int k, vector<int> &arr, int &cnt)
{
    if (i == n)
    {
        if (sum == k)
            cnt++;
        return;
    }
    sum += arr[i];
    cnt_subsequences(i + 1, n, sum, k, arr, cnt);
    sum -= arr[i];
    cnt_subsequences(i + 1, n, sum, k, arr, cnt);
}

// Another way of doing count subsequences question without any extra variable
int cnt_subsequences2(int i, int n, int sum, int k, vector<int> &arr)
{
    if (i == n)
    {
        if (sum == k)
            return 1;
        return 0;
    }
    sum += arr[i];
    int left = cnt_subsequences2(i + 1, n, sum, k, arr);
    sum -= arr[i];
    int right = cnt_subsequences2(i + 1, n, sum, k, arr);
    return right + left;
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    vector<int> temp;
    cout << "subsequences with sum k are :" << endl;
    ksum_subsequence1(0, n, 0, k, arr, temp);
    int cnt = 0;
    cout << "count of subsequences with sum k are : " << endl;
    cout << cnt_subsequences2(0, n, 0, k, arr) << endl;
    return 0;
} 