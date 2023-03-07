#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--) 

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
// quicksort is based on divider and conquer algorthim
// dividing of array is called partition
// quicksort can be performed various ways
// 1.taking first element as pivot
// 2.Taking last element as pivot
// 3.Taking random element as pivot
// 4.Taking median as pivot

// In this we will look at the quicksort taking first element as pivot
// partition is the main logic
// After partition all the elements which are smallet than pivot will be on left side and all greater elements will be on right side of pivot
// equal elements to pivot are also left

//pivot element as first element 
/*
Time Complexity : O(nlogn)
One thing to be noted that the array is not splitted in equal halves in the quicksort. The array is splitted based on the partitionIndex.
Space Complexity : O(1)
Does not use any  extra space, If the recursion stack space is considered then it would O(logn) space.
*/
int quickfirst(int *arr, int l, int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while (i < j)
    {
        // find the element which is greater than the pivot from left
        while (i <= h-1 && arr[i] <= pivot)
            i++;
        // find the element which is smaller than the pivot from right
        while (j >= l+1 && arr[j] > pivot)
            j--;
        // swap these elements and continue
        if (i < j)
            swap(arr[i], arr[j]);
    }
    // After the completion of while loop, j points to the correct location of the pivot element in sorted array
    // so swap the pivot element and the arr[j]
    // now the pivot is at correct position
    swap(arr[l], arr[j]);
    // now return the j
    return j;
}

void quicksort(int *arr, int l, int h)
{
    if (l < h)
    {
        int pivot = quicklast(arr, l, h);
        // now pivot element is placed at correct location
        // now apply same procedure on the left subarray and rightsubarray of the pivot

        // calling for left subarray
        quicksort(arr, l, pivot - 1);

        // calling for right subarray
        quicksort(arr, pivot + 1, h);
    }
    // in this way for each call one element is placed at correct location
    /*-----------------------NOTE-----------------------------------
    If the array is sorted and the pivot is poorly picked (e.g for sorted array if the pivot is first element) then the time complexity of the algo would be O(n*n) 
    */
} 
int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    quicksort(arr, 0, n - 1);
    fo(i, n)
            cout
        << arr[i] << " ";
    return 0;
}  