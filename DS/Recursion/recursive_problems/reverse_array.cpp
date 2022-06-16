#include <bits/stdc++.h>
using namespace std;
// Recursion using the two variables
void reverse2(int i, int j, int *arr)
{
    if (i < j)
    {
        swap(arr[i], arr[j]);
        reverse2(i + 1, j - 1, arr);
    }
}
// Recursion using the single variable
void reverse1(int i, int n, int *arr)
{
    if (i < n - 1 - i)
    {
        swap(arr[i], arr[n - 1 - i]);
        reverse1(i + 1, n, arr);
    }
} 
int main()

{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    reverse1(0, n, arr);
    cout << "array after reversing" << endl;
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
    return 0;
} 