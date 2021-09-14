// for a given sorted array we should find the first and last occurence of the number in the array using binary search
#include <bits/stdc++.h>
using namespace std;

// finding the first occurence of the number
int first(int *arr, int target, int n)
{
    int low = 0, high = n - 1;
    int mid, ans = -1;
    while (low <= high)
    {

        mid = (low + high) >> 1;
        // when the arr[mid] is equal to target,store it into ans, as we have to find the first occurence of the number,so we don't bother about the right half, so make high to mid-1
        if (arr[mid] == target)
        {
            ans = mid;
            high = mid - 1;
        }
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return ans;
} 
// finding the last occurence of the number
int last(int *arr, int target, int n)
{
    int low = 0, high = n - 1;
    int mid, ans = -1;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        // if arr[mid] equals to target store that location into ans,as we have to find the last occurence of the number ,so we bother about teh right half,so make low to mid+1
        if (arr[mid] == target)
        {
            ans = mid;
            low = mid + 1;
        }
        else if (arr[mid] < target)
            low = mid + 1;

        else
            high = mid - 1;
    }
    return ans;
}
int main()

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cin >> target;
    cout << first(arr, target, n) << endl;
    cout << last(arr, target, n) << endl;

    return 0;
}