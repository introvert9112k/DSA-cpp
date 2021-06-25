#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
int binary_search1(int *arr, int target, int n)
{
    int low = 0, high = n - 1;
    int mid;
    while (low <= high)
    {
        mid = (low + high) >> 1;
        if (arr[mid] == target)
            return mid;

        else if (arr[mid] > target)
            high = mid - 1;
        else
            low = mid + 1;
    }
    return -1;
}
int binary_search2(int *arr,int target,int n)
{
    int low = 0, high = n - 1;
    int mid;
    while( (high - low )> 1)
    {
        mid = (low + high) >> 1;
        if(arr[mid] > target)
             high= mid - 1;
        else
            low = mid;
    }
    // this while loop ends up in pointing the low and high pointers adjacent elements 
    // any of the low or high is our target's location 
    // it is more easily understandable than the low <= high conditons 
    if(arr[low] == target)
        return low;
    else if (arr[high] == target)
        return high;
    return -1;

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
    sort(arr, arr + n);
    int res = binary_search2(arr, target, n);
    res != -1 ? (cout << "the target found at index : " << res << endl) : (cout << "target not found");
    return 0;
} 