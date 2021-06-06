// problem statement
// given an array find the largest sum contigous sub array and return the largest sum of the sub array

// there are three appraoches
// Approach 1
//  brute force approach
// Approach 2
// prefix array approach
// Approach 3
// kandanes algorthim
#include <bits/stdc++.h>
#define int long long int
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
void brute_force(int *arr, int n)
{
    int max = INT_MIN;
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
        {
            int sum = 0;
            for (int k = i; k <= j; k++)
                sum += arr[k];

            if (sum > max)
                max = sum;
        }
    }
    cout << max << endl;
    // time complexity is O(N^3)
    // space complexity is O(1) 
}

void prefix_array(int *arr, int n)
{
    int prefix[n + 1];
    int max = INT_MIN;
    int sum;
    prefix[0] = 0;
    for (int i = 1; i <= n; i++)
        prefix[i] = prefix[i - 1] + arr[i];
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j++)
            sum = prefix[j] - prefix[i - 1];
        if (sum > max)
            max = sum;
    }
    cout << max << endl;
    // time complexity is O(N^2)
    // space complexity is O(N) 
}

void kanadanes(int *arr,int n)
{
    int max = INT_MIN;
    int max_till_now = 0;
    for (int i = 1; i <= n; i++)
    {
        max_till_now += arr[i];
        if(max_till_now < 0)
            max_till_now = 0;
        if(max_till_now > max )
            max = max_till_now;
    }
    cout << max << endl;
    // space is O(1)
    // time is O(n)
}  
int32_t main()
{
    int n;
    scan(n);
    int arr[n + 1];
    for (int i = 1; i <= n; i++)
        scan(arr[i]);
    brute_force(arr, n);
    prefix_array(arr, n);
    kanadanes(arr, n);
    return 0;
}
 