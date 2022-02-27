#include <bits/stdc++.h>
using namespace std;

// Time complexity ---- O(nlogn)
// reference take U farward
// This only gives the length of  longest increasing sequence,the sequence in temp is not the lis

int lis(vector<int> &arr)
{
    vector<int> temp;
    int n = arr.size();
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
        if (temp.back() < arr[i])
            temp.push_back(arr[i]);
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
}
int main()

{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "length of the longest increasing subsequence in array is : " << lis(arr) << endl;

    return 0;
} 