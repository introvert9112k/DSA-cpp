/*--------------------Insertion Sort-----------------------*/
#include <bits/stdc++.h>
using namespace std;
/*
Algorithm :
1.Intution of the Algorithm is selected an index i and insert the element in its corresponding position in the arr[0,i-1].
2.For the index i,the array [0,i-1] would be sorted,so for the value arr[i],find the correct position of it in the sorted arr[0,i-1] and insert it there.

Time Compelxity : O(n*n)
Space Complexity : O(1)
*/
void insertionSort(int n, vector<int> &arr)
{
    for (int i = 1; i < n; ++i)
    {
        for (int j = i; j > 0 && arr[j - 1] > arr[j]; --j)
        {
            swap(arr[j], arr[j - 1]);
        }
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
    insertionSort(n, arr);
    for (auto &val : arr)
        cout << val << " ";
    return 0;
} 