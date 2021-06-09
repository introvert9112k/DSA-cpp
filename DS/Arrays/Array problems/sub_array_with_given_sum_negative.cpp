// Given an unsorted array A of size N that contains , find a continuous sub-array which adds to a given number S.

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
void given_sum(int *arr,int n,int s)
{
    unordered_map<int, int> map;
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
        if(sum == s)
            cout << 0 << " " << i << endl;
        if(map[sum-s])
            cout << map[sum - s]+1 << " "<<i << endl;
        map[sum] = i;
    }
    cout << "sub array not present" << endl;
} 

int32_t main()
{
    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
        scan(arr[i]);
    int s;
    cin >> s;
    given_sum(arr, n, s);

    return 0;
} 