// problem statement 
// Given an array of integers and a number K. Find the count of distinct elements in every window of size K in the array.

// Example 1:

// Input:
// N = 7, K = 4
// A[] = {1,2,1,3,4,2,3}
// Output: 3 4 4 3
// Explanation: Window 1 of size k = 4 is
// 1 2 1 3. Number of distinct elements in
// this window are 3. 
// Window 2 of size k = 4 is 2 1 3 4. Number
// of distinct elements in this window are 4.
// Window 3 of size k = 4 is 1 3 4 2. Number
// of distinct elements in this window are 4.
// Window 4 of size k = 4 is 3 4 2 3. Number
// of distinct elements in this window are 3.
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
void unique_elements(int *arr,int n, int k)
{
    vector<int> v;
    unordered_map<int, int> map;
    for (int i = 0; i < k; i++)
        map[arr[i]]++;
    v.push_back(map.size());
    for (int i = k; i < n; i++)
    {
        if(arr[i-k] == 1)
            map.erase(arr[i - k]);
        else
            map[arr[i - k]]--;
        map[arr[i]]++ v.push_back(map.size());
    }
    for(auto value : v)
        cout << value << " ";
} 
// Reference 
// video https://www.youtube.com/watch?v=j48e8ac7r20
// gfg https://practice.geeksforgeeks.org/problems/count-distinct-elements-in-every-window/1#

int32_t main()
{
    int n,k;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    cin >> k;
    unique_elements(arr, n, k);

    return 0;
} 