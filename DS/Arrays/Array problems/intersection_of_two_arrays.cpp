// problem statement
// given two arrays find the intersection of two arrays
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
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
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
unordered_set<int> intersection(int *arr1, int *arr2, int n, int m)
{
    unordered_set<int> s1, s2;
    fo(i, n)
        s1.insert(arr1[i]);
    fo(i, m)
    {
        if (s1.find(arr2[i]) != s1.end())
            s2.insert(arr2[i]);
    }
    return s2;
}

int32_t main()
{

    int n, m;
    cin >> n >> m;
    int arr1[n], arr2[m];
    fo(i, n)
        scan(arr1[i]);
    fo(i, m)
        scan(arr2[i]);
    unordered_set<int> k = intersection(arr1, arr2,n,m);
    for (auto x : k)
        cout << x << " ";
    return 0;
} 