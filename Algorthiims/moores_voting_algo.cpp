// problem statement
// Given an array find the element that apperas more than the n/2 times in the array
// Note : Array should be in such a way that the there is always a majority element

#include <bits/stdc++.h>
using namespace std;

// General Approach
// Time -- O(N)
// Space -- O(1)
int findmajority(int arr[], int n)
{
    unordered_map<int, int> freq;
    for (int i = 0; i < n; i++)
        freq[arr[i]]++;
    for (int i = 0; i < n; i++)
        if (freq[arr[i]] > n / 2)
            return arr[i];
    return -1;
}

// Time -- O(N)
// Space --- O(1)
int mooresvoting(int arr[], int n)
{
    int count = 0, candidate = 0;
    for (int i = 0; i < n; i++)
    {
        if (count == 0)
            candidate = num;
        num == candidate ? count++ : count--;
    }
    return candidate;
}
// reference : Take u forward video ,moores voting algorthim
int main()

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    findmajority(arr, n);
    return 0;
}     