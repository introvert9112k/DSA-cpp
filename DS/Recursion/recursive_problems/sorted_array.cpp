#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int is_sorted(int *arr,int i,int n)
{
    static int count = 0;
    if(arr[i] < arr[i+1])
        count++;
    if(arr[i] > arr[i+1])
        return -1;
    if(count == n-1)
        return 1;
    return is_sorted(arr, i + 1, n);
}
int main() 

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    // sort(arr, arr + n);
    int res = is_sorted(arr, 0, n);
    res == 1 ? (cout << "array is sorted") : (cout << "array not sorted");

    return 0;

} 