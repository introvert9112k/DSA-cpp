// problem statement 
// given an sorted array which contains one unique element and rest are repeated twice ,we should find the unique eleemnt in the sorted array 
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
int linear_search(int *arr,int n)
{
    for (int i = 0; i < n-1; i+=2)
    {
       if(arr[i] != arr[i+1])
           return arr[i];
    }
    return arr[n - 1];
    // Time O(N)
    // Space O(1)
}
int xor_approach(int *arr, int n)
{
    int ans = 0;
    fo(i, n)
        ans ^= arr[i];
    return ans;
    // Time O(N)
    // Space O(1)
}
int binary_search_approach(int *arr, int n)
{
    int low = 0,high=n-1;
    int mid;
    if(n==1 or arr[0]!=arr[1])
        return arr[0];
    else if(arr[n-1]!=arr[n-2])
        return arr[n - 1];
    while(low<=high)
    {
        mid = (low + high) >> 1;
        if( ( arr[mid-1]!=arr[mid] ) and ( arr[mid+1] != arr[mid] ))
            return arr[mid];
        else if(arr[mid-1] == arr[mid])
        {
            int lc = mid - low + 1;
            if(lc &1)
                high = mid - 2;
            else
                low = mid + 1;
        }
      else if(arr[mid+1] == arr[mid])
      {
          int rc = high - mid + 1;
          if(rc & 1)
              low = mid + 2;
          else
              high = mid - 1;
      }
    }
    return -1;
    //   Time O(logN)
    //   space O(1)
} 

// Reference 
// pepcoding searching and sorting playlist
int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    cout<<"the unique element is : " << linear_search(arr, n) <<endl;
    return 0;
} 