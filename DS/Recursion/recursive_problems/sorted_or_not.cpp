// problem statement 
// given an array check whether the array is sorted or not recursively
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
bool sorted(int *arr,int i, int n)
{   
    // checking whether the array is sorted in ascending order or not
    if(n==1 or i==n)
        return true;
    // if we want to check for descending order then use < symbol in this base case
    if(arr[i-1] > arr[i])
        return false;
    return sorted(arr, i + 1, n);
} 
int main() 

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sorted(arr, 1, n) ? (cout << "array is sorted" ) : (cout << "array is not sorted");

    return 0;

}