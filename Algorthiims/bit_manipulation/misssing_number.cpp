// problem statement 
// given an array contains the consecutive integers from 1 to n ,in this array one number is repeating twice and another is missing ,find the repaeating and missing element 
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
void missing_duplicate(int *arr, int n)
{
    int ans = 0;
    for(int i = 0; i < n; i++)
        ans ^= arr[i];
    for (int i = 1; i <= n; i++)
        ans ^= i;
    int x = 0, y = 0;
    int rsbm = ans & -ans;
    for (int i = 0; i < n; i++)
      {
          if(rsbm & arr[i])
              x ^= arr[i];
           else
               y = y ^ arr[i];
      }
      for (int i = 1; i <= n; i++)
      {
          if(rsbm & i)
              x ^= i;
           else
               y ^= i;
      }
      for (int i = 0; i < n; i++)
      {
          if(arr[i] == x)
           {
               cout << "duplicate element is  : " << x << endl;
               cout << "the misssing element is : " << y << endl;
               break;
           }
           else if(arr[i]==y) 
           {
               cout << "duplicate element is : " << y << endl;
               cout << "missing element is : " << x << endl;
               break;
           } 
      } 
} 
// Reference :
// pepcoding bit manipulation playlist

int32_t main() 
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
     cin >>arr[i];
    missing_duplicate(arr, n);

    return 0;
} 