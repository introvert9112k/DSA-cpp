/*-------------------------Selection Sort ------------------------*/
#include <bits/stdc++.h>
using namespace std;
/*
Algorithm :
1. Intuition behind this algo is,to find the minimum element in each iteration and place in its corresponding position.
2.For the index i arr[0,i-1] will be sorted and arr[i+1,n-1] is unsorted.
3.Find the minimum element in the arr[i,n-1] and swap the value with the current Index i.e 'i'.

Time Complexity  : O(n*n)
Space Complexity : O(1)
*/
void selectionSort(int n, vector<int> &arr)
{
    for (int i = 0; i < n; ++i)
    {
        int minIndex = i;
        for (int j = i + 1; j < n; ++j)
        {
            if (arr[j] < arr[minIndex])
                minIndex = j;
        }
        swap(arr[i], arr[minIndex]);
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
    selectionSort(n, arr);
    for (auto &val : arr)
        cout << val << " ";
} 