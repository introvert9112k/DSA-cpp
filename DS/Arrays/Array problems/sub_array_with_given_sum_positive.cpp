// problem statement
// given a array with all the positive elements, find whether there exists a sub array with given sum, if exists return true, else return false 
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
bool given_sum(int *arr, int n,int s)
{
    int current_sum = 0, start = 0;
    for (int i = 0; i <= n; i++)
    {
        while(current_sum > s and start < i)
        {
            current_sum = current_sum - arr[start];
            start++;
        }
        if(current_sum == s)
            return true;
        if(i < n)
            current_sum += arr[i];
    }
    return false;
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
    cout << given_sum(arr, n, s) << endl;
    return 0;
}  