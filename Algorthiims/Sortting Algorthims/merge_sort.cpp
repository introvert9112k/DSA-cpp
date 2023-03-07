#include <bits/stdc++.h>
using namespace std;
/* https://www.youtube.com/watch?v=ogjf7ORKfd8
Time Complexity : o(nlogn)
Space Complexity : O(n)
See the youtube video for the How the time Compleixty is O(nlogn)
*/

void mergeTwoSortedArrays(vector<int> &nums, int low, int mid, int high)
{
	int size = high - low + 1;
	vector<int> mergedArray(size);
	for (int i = low, j = mid + 1, k = 0; k < size; ++k)
	{
		if (i <= mid && j <= high)
			mergedArray[k] = nums[i] < nums[j] ? nums[i++] : nums[j++];
		else if (i <= mid)
			mergedArray[k] = nums[i++];
		else
			mergedArray[k] = nums[j++];
	}
	for (int i = low; i <= high; ++i)
		nums[i] = mergedArray[i - low];
}

void mergeSort(int low, int high, vector<int> &nums)
{
	if (low >= high)
		return;
	int mid = low + (high - low) / 2;
	mergeSort(low, mid, nums);
	mergeSort(mid + 1, high, nums);
	mergeTwoSortedArrays(nums, low, mid, high);
}

int main()
{
	int n;
	cin >> n;
	vector<int> nums(n);
	for (int i = 0; i < n; ++i)
	{
		cin >> nums[i];
	}
	mergeSort(0, nums.size() - 1, nums);
} 