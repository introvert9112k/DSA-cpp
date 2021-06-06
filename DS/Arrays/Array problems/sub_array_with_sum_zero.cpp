// problem statement 
// given an array we should find the sub array with sum equal to zero ,if sub array is not found return -1

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
int sum_zero(int *arr,int n)
{
    unordered_map<int, int> map;
    int prefix[n + 1];
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    for (int j = 1; j <= n; j++)
    {
        if(prefix[j] == 0 or arr[j] == 0 or map[prefix[j]] )
            return 1;
        map[prefix[j]]++;
    } 
    return -1;
}
// Algorithm 
// first consturct the prefix array of the given array 
// there will be a sub array with sum zero if it satisfies any of the three conditions 

// 1.if the prefix arrray element is zero 
// 2.if the zero is itself in the array 
// 3.when there are duplicates in the prefix array 

int32_t main()
{

    int n;
    cin >> n;
    int arr[n+1];
    for (int i = 1; i <= n; i++)
        scan(arr[i]);
    print(sum_zero(arr, n));
    
    return 0;
} 
