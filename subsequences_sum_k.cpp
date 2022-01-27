#include <bits/stdc++.h>
using namespace std;

void subsequences_sum_k(vector<int> &arr, int ind, int n, int k, vector<int> &temp, int sum)
{
    if (ind == n)
    {
        if (sum == k)
        {
            for (auto &it : temp)
                cout << it << " ";
            cout << endl;
        }
        return;
    }
    sum += arr[ind];
    temp.push_back(arr[ind]);
    subsequences_sum_k(arr, ind + 1, n, k, temp, sum);
    temp.pop_back();
    sum -= arr[ind];
    subsequences_sum_k(arr, ind + 1, n, k, temp, sum);
} 
int main()

{
    int n, k;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cin >> k;
    vector<int> temp;
    subsequences_sum_k(arr, 0, n, k, temp, 0);
    return 0;
}
