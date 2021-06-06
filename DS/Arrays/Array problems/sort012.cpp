#include <iostream>
using namespace std;

void sort012(int arr[], int n) {
    //Write your code here
    int i=0,j=n-1,k=0;
    while(k<=j)
    {
        if(arr[k]==0)
        {
            swap(arr[k], arr[i]);
            i++;
            k++;
        } 
        else if (arr[k]==1)
            k++;
       else if(arr[k]==2)
       {
           swap(arr[k], arr[j]);
           j--;
       }
       
    } 
} 

int main()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    sort012(arr, n);
    for(auto x : arr)
         cout<<x<<" ";
} 
