#include <bits/stdc++.h>
using namespace std;
int inversions = 0;

void merge(int *arr, int start, int mid, int end)
{
    int temp[end - start + 1];
    int i = start, j = mid + 1, k = 0;
    while (i <= mid and j <= end)
    {
        if (arr[i] <= arr[j])
        {
            temp[k] = arr[i];
            i++;
            k++;
        }
        else
        {
            inversions += mid - i + 1; //this line which differentiates mergesort and inversions

            // if any of the element in left side array is greater than the element in the right side array then all the elements of the left side array are also greater than that element ,because the array's are sorted
            // if ith element of left side array is greater than the element in right side array then the remaining  elements i.e mid-i+1 are also greater than that element so we add mid-i+1 to inversions count
            temp[k] = arr[j];
            j++;
            k++;
        }
    } 
    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }
    while (j <= end)
    {
        temp[k] = arr[j];
        j++;
        k++;
    }
    for (int i = 0; i < k; i++)
        arr[i + start] = temp[i];
} 
void mergesort(int *arr, int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) >> 1;
        mergesort(arr, start, mid);
        mergesort(arr, mid + 1, end);
        merge(arr, start, mid, end);
    }
}
int main()

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    mergesort(arr, 0, n - 1);
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << "\ninversions " << inversions << endl;
    return 0;
}