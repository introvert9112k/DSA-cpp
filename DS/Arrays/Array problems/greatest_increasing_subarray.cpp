#include<bits/stdc++.h>
using namespace std;
#define n 10
int prefix[n + 1];
void calculateprefix(int *arr) 
{
    prefix[1] = 1;
    for (int i = 2; i <= n; i++)
    {
        if(arr[i-1]<arr[i])
            prefix[i] = prefix[i - 1] + 1;
        else
            prefix[i] = prefix[i - 1];
    }
} 

int main() 

{  

    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        cin >> arr[i];
    calculateprefix(arr);
    int q;
    cin >> q;
    while(q--)
    {
        int l, r;
        cin >> l >> r;
        cout << prefix[r] - prefix[l] + 1 << endl;
    }

    return 0;

} 