#include <bits/stdc++.h>
using namespace std;
/*-------------------Bubble Sort-------------*/

/*----------------------Algorithm-------------------------------
1. For the index i the sub array arr[i+1,n-1] would be sorted,and in the current ith iteration we bring the greatest element in the sub array arr[0,i] to the index i, through adjacent swaps.
2. Time Complexity : O(n*n)
Space Complexity : O(1)
*/
void bubbleSort(int n, vector<int> &arr)
{
    for (int i = n - 1; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
            if (arr[j] > arr[j + 1])
                swap(arr[j], arr[j + 1]);
    }
}

int main()
{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> arr[i];
    }
    bubbleSort(n, arr);
    for (auto &val : arr)
        cout << val << " ";
} 