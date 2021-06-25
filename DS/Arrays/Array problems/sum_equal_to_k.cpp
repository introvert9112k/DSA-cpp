// problem statement 
// given an array find whether there exists a sub aray with sum k
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
void brute_force(int *arr, int n,int k)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            for (int m = i; m <= j; m++)
           {
               sum += arr[m];
           }
           if(sum == k)
             {
                 cout << "true" << endl;
                 return;
             }
             sum = 0;
        }
    }
}

void prefix_sum(int *arr, int n,int k)
{
    int prefix[n+1];
    prefix[0] = 0;
    for (int i = 0; i < n; i++)
        prefix[i + 1] = prefix[i] + arr[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            if((prefix[j+1] - prefix[i])==k)
               { cout << "true" << endl;
                   return;
               }
        }
    } 
} 
// this valid for only positive elements only
void kanadanes_algorthim(int *arr,int n,int k)
{
    int num = n << 1;
    int sum = arr[0];
    int right = 0, left = 0;
    while(num--)
    {
        if(sum == k)
        {
            cout << "true" << endl;
            return;
        }
        else if(sum < k)
        {
            sum = sum + arr[++right];
        }
        else
            sum = sum - arr[left++];
    }
} 
void hash_map(int *arr, int n,int k)
{
    int current_sum = 0;
    unordered_map<int, int> map;
    for (int i = 0; i < n; i++)
    {
          current_sum += arr[i];
          map[current_sum]++;
         if(map[current_sum - k])
          {
              cout << "true" << endl;
              return;
          }
    }
} 
    int32_t main()
{

    int n,k;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    cin >> k;
  hash_map(arr, n,k); 
    return 0;
} 