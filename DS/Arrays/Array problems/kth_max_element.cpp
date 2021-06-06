// problem statement 
// for the given array find the kth max element 

// Approach 
// this can be done in two ways 
// 1.first sort the array and return the kth smallest element 
// 2.run the priority queue for k times and return the kth element 
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
#define s(n) scanf("%d",&n)
#define p(n) printf("%d",n) 
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
    s(n);
    int arr[n];
    fo(i, n)
        s(arr[i]);
    sort(arr, arr + n,cmp); //sorting in descending order 
    // array elements should be unique /
    int k;
    s(k); //time complexity is O(nlogn)
    cout << arr[k - 1] << endl;

    priority_queue<int> pq(arr,arr+n);
    // by default it is maximum heap 
    int ans,i = 1; 
    while(!pq.empty())
    {
        if(i==k)
        {
            ans = pq.top();
        }
        pq.pop();
        i++;
    }
    // for priority queue time complexity is O(n+klogn) 
    // n is for pushing array elements into the priority queue and klogn is for finding the kth maximum from priority queue 
    // pushing and popping in priority queue takes logN time /
    cout << ans << endl;
    return 0;
}   