// problem statment
// given an array,which has two numbers occuring odd number of times and remaining numbers occuring even number of times,find these two odd
// occuring numbers
#include <bits/stdc++.h>
using namespace std;

pair<int, int> twoodd(vector<int> arr, int n)
{
    int Xor = 0;
    for (int i = 0; i < n; i++)
        Xor ^= arr[i];
    int rsbm = Xor & -Xor;
    int xor1 = 0, xor2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (arr[i] & rsbm)
            xor1 ^= arr[i];
        else
            xor2 ^= arr[i];
    }
    return {xor1, xor2};
} 

int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    pair<int, int> res = twoodd(arr, n);
    cout << res.first << " " << res.second << endl;
    return 0;
} 