// problem statemet 
// Given an array of N integers, and an integer K, find the number of pairs of elements in the array whose sum is equal to K.
// 
// 
// Example 1:
// 
// Input:
// N = 4, K = 6
// arr[] = {1, 5, 7, 1}
// Output: 2
// Explanation: 
// arr[0] + arr[1] = 1 + 5 = 6 
// and arr[1] + arr[3] = 5 + 1 = 6.
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
void count_pairs(int *arr,int n,int k)
{
    int count = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
        int x = k - arr[i];
        if(map[x] == 0)
            map[arr[i]]++;
        else 
        {
            count += map[x];
            map[arr[i]]++;
        }
    }
    print(count);
} 

int32_t main()
{

    int n;
    scan(n);
    int arr[n];
    fo(i, n)
        scan(arr[i]);
    int k;
    scan(k);
    count_pairs(arr, n,k);
    return 0;
} 
