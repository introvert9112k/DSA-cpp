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
// Given an array A[] with N elements , you need to find the sum all sub arrays of array A. Since the sum could be very large print the sum modulo (109+7).


// Example 1:

// Input:
// N = 3
// A[] = {1, 2, 3}
// Output: 20
// Explanation:
// All subarrays are [1], [2], [3],
// [1,2], [2,3], [1,2,3].
// Thus total sum is 20.
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
int gcd(int a,int b)
{
      if(b==0)
          return a;
      return gcd(b,a%b);
}
int solve()
{
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n;i++)
        cin >> arr[i];
    int sum = 0;
    int i = 1, j = n;
    for (int k = 0; k < n; k++)
    {
        sum = (sum + arr[k]*i*j)%mod;
        i++;
        j--;
    }
    return sum % mod;
} 
int32_t main()
{ 
     
     ios_base::sync_with_stdio(false);
     cin.tie(NULL);
     cout.tie(NULL);
     srand(time(NULL));
     int t;
     cin>>t;
     while(t--)
     {

          cout<<solve()<<endl;

     }
    return 0;
} 