#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define scan2(g, h) scanf("%lld %lld", &g, &h)
#define scan3(x, y, z) scanf("%lld %lld %lld", &x, &y, &z)
#define print(g) printf("%lld", g)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--)
#define umii unordered_map<int, int>
#define umci unordered_map<char, int>
#define vvi vector<vector<int>>

using namespace std;
const int MAX = 1000001;
int fact[MAX];
int invfact[MAX];

int mpower(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % mod;
        a = (a * a) % mod;
        b = b >> 1;
    }
    return result;
}
int ncr(int n, int r)
{
    fact[0] = 1;
    invfact[0] = 1;
    for (int i = 1; i < MAX; i++)
    {
        fact[i] = (fact[i - 1] * i) % mod;
        invfact[i] = mpower(fact[i], mod - 2);
    }
    if (n < 0 or r < 0 or r > n)
        return 0;
    int num = fact[n];
    int den = (invfact[r] * invfact[n - r]) % mod;
    return (num * den) % mod;
}
bool cmp(int a, int b)
{
    return a > b;
}
bool prime(int num)
{
    for (int i = 2; i * i <= num; i++)
        if (num % i == 0)
            return false;
    return true;
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
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

int lis(vector<int> &arr)
{
    vector<int> temp;
    int n = arr.size();
    temp.push_back(arr[0]);
    for (int i = 1; i < n; i++)
    {
// This is code for finding out the length of longest increasing subsequence
// if want to find for longest non decreasing subsequence, take <= and use upper_bound instead of lower bound
        if (temp.back() < arr[i])
            temp.push_back(arr[i]);
        else
        {
            int ind = lower_bound(temp.begin(), temp.end(), arr[i]) - temp.begin();
            temp[ind] = arr[i];
        }
    }
    return temp.size();
} 

void solve()
{
}
int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {

        solve();
    }
    return 0;
}