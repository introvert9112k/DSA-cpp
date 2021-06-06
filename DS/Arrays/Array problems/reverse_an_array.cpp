// problem statement
// reverse an array
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
#define s(n) scanf("%d", &n)
#define p(n) printf("%d", n)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--)
#define foe(arr)   for(auto x : arr) cout << x << " " 

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

int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
      cin>>arr[i];
    int start = 0;
    int end = n - 1;
    while (start < end)
    {
        swap(arr[start], arr[end]);
        start++;
        end--;
    }
    foe(arr); 
    return 0;
}  