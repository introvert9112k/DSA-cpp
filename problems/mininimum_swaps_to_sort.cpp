// problem statement
// Given an array find the minimum number of swaps required to sort the array
// Here we apply the reverse logic,first we sort the array and find out minimum swaps required to make sorted array to original array

#include <bits/stdc++.h>
using namespace std;
 
void findminswaps(vector<int> &arr, int n)
{
    vector<pair<int, int>> pair;
    for (int i = 0; i < n; i++)
        pair.push_back({arr[i], i});
    sort(pair.begin(), pair.end());
    int swaps = 0;
    for (int i = 0; i < n; i++)
    {
        if (i == pair[i].second)
            continue;
        else
            swaps++, swap(pair[i], pair[pair[i].second]), i--;
    }
    cout << "Minimum swaps required to sort the array is " << swaps << endl;
}

int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findminswaps(arr, n);
    return 0;
}