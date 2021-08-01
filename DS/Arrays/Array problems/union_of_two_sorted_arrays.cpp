#include <iostream>
#include <bits/stdc++.h>
using namespace std;
vector<int> findUnion(int *arr1, int *arr2, int n, int m)
{
    vector<int> v;
    int i = 0, j = 0;
    while (i < n and j < m)
    {
        if ((arr1[i] < arr2[j]) and (i == 0))
        {
            v.push_back(arr1[i]);
            i++;
        }
        else if ((arr2[j] < arr1[i]) and (j == 0))
        {
            v.push_back(arr2[j]);
            j++;
        }
        else if ((arr1[i] < arr2[j]))
        {
            if (arr1[i - 1] != arr1[i])
                v.push_back(arr1[i]);
            i++;
        }
        else if ((arr2[j] < arr1[i]))
        {
            if (arr2[j - 1] != arr2[j])
                v.push_back(arr2[j]);
            j++;
        }
        else
        {
            if (arr1[i - 1] != arr1[i])

                v.push_back(arr1[i]);
            i++;
            j++;
        }
    }
    while (i < n)
    {
        if (arr1[i - 1] != arr1[i])

            v.push_back(arr1[i]);
        i++;
    }
    while (j < m)
    {
        if (arr2[j - 1] != arr2[j])

            v.push_back(arr2[j]);
        j++;
    }
    return v;
    // Time O(N+M)
    // Space O(N+M)
} 
int main()
{
    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    for (int i = 0; i < n; i++)
        cin >> arr1[i];
    for (int j = 0; j < m; j++)
        cin >> arr2[j];
    vector<int> v = findUnion(arr1, arr2, n, m);
    for (auto x : v)
        cout << x << " ";
} 