// problem statement 
// given an array which contains pairs of elements that mean each element is repeated twice except one element,we should find the unique element in array
// Approach
// let array elements be 23 456 23 12 34 12 34 
// in this array 23,12,34 occured twice and 456 ocurred only once 
// let us take the xor of all the elements 
// so 23^456^23^12^34^12^34 this also can be written as 23^23^12^12^34^34^456 as order does not matter in xor 
// we know that x^x is 0 so  23^23^12^12^34^34^456 this converges to 0^456 so xor with zero is number itself.
// So in this we can find the unique element in array 
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define si stack<int> 
#define li list<int> 
#define endl  "\n"  
#define pi pair<int,int> 
#define scan(h) scanf("%lld",&h)
#define st(g,h) scanf("%lld %lld",&g,&h) 
#define print(g) printf("%lld",g) 
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
void unique_element(int *arr,int n)
{
    int unique = 0;
    fo(i, n)
        unique = unique ^ arr[i]; //taking the xor of all the array elements
    // at last unique value becomes our desired answer
    cout << "unique element in the array is : " << unique << endl;
}

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
        scan(arr[i]);
    unique_element(arr, n);

    return 0;
} 