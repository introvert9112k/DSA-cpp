#include <bits/stdc++.h>
using namespace std;
/*------------------Quick Select-------------------------------------
Qucik select is used to find the kth largest/smallest element in the array.
It is used to find the specific element.
The alogrithm works similar to the quick sort.

-----------------------Difference between quick sort and quick select--------------------------------
Quick sort sorts all the elements of the array, that mean it takes the two halves.
whereas quick select finds where is the required element and takes that half only.
So Time complexity is far less than the quick sort in average case.

In Best case Time Complexity : O(N)
In Worst Case Time Complexity : O(N^2)

*/

/*Quick select Algorithim,similar to partion of the quick sort*/
int quick_select(int low, int high, vector<int> &nums)
{
    int pivot = nums[high], ind = high, n = nums.size();
    while (low < high)
    {
        while (low < high && nums[low] <= pivot)
            low++;
        while (high > low && nums[high] > pivot)
            high--;
        if (low < high)
            swap(nums[low], nums[high]);
    }
    swap(nums[low], nums[ind]);
    return low;
}
/*Driving code for finding kth smallest element*/
int kth_smallest(int low, int high, vector<int> &nums, int k)
{
    if (low < high)
    {
        int ind = quick_select(low, high, nums);
        if (ind + 1 == k)
            return nums[ind];
        /*This is where quick sort and quick select differ,choose only the half where the element lies*/
        return ind + 1 < k ? kth_smallest(ind + 1, high, nums, k) : kth_smallest(low, ind - 1, nums, k);
    }
    return -1;
}
/*Driving code for finding kth largest element*/
int kth_largest(int low, int high, vector<int> &nums, int k)
{
    if (low < high)
    {
        int ind = quick_select(low, high, nums);
        if (ind + 1 == nums.size() - k + 1)
            return nums[ind];
        return ind + 1 < nums.size() - k + 1 ? kth_largest(ind + 1, high, nums, k) : kth_largest(low, ind - 1, nums, k);
    }
    return -1;
}
int main()
{
    int n, k;
    cin >> n >> k;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << k << "th smallest element is : " << endl;
    cout << kth_smallest(0, n - 1, arr, k) << endl;
    cout << k << "th largest element is : " << endl;
    cout << kth_largest(0, n - 1, arr, k) << endl;
    return 0;
} 