#include <bits/stdc++.h>
using namespace std;

void Heapify(int arr[], int i, int n) 
{
    int ri = 2 * i + 2; /*right child*/
    int li = 2 * i + 1; /*left child*/
    int smallest = i; /*intially assume violated value in Min value*/
    if (li < n && arr[li] < arr[smallest])
        smallest = li;
    if (ri < n && arr[ri] < arr[smallest])
        smallest = ri;
    /*smallest will store the minvalue index*/
    /*If the Minimum among the three nodes is the parent itself,
    that is Heap property satisfied so stop else call function recursively on Minvalue node*/
    if (smallest != i)
    {
        swap(arr[i], arr[smallest]);
        Heapify(arr, smallest, n);
    }
}

void print(int arr[], int n)
{
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main()

{
    int arr[] = {9, 3, 2, 5, 4, 6, 7, 8, 1};
    int n = sizeof(arr) / sizeof(arr[0]);
    int lastnonleaf = n / 2 - 1;
    for (int i = lastnonleaf; i >= 0; i--)
        Heapify(arr, i, n);
    print(arr, n);
    return 0;
}   