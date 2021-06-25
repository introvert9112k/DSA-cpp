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
int quick(int *arr, int l,int h)
{
    int pivot = arr[l];
    int i = l;
    int j = h;
    while(i<j)
    {
        while(arr[i]<=pivot)
            i++;
        while(arr[j] > pivot )
            j--;
        if(i<j)
          swap(arr[i], arr[j]);

    }
    swap(arr[l], arr[j]);
    return j;
} 
void quicksort(int *arr,int l, int h)
{
    if(l<h)
    {
        int pivot = quick(arr, l, h);
        quicksort(arr, l, pivot - 1);
        quicksort(arr, pivot + 1, h);
    }
}
int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    quicksort(arr, 0, n - 1);
    fo(i, n)
            cout
        << arr[i] << endl;
    return 0;
} 