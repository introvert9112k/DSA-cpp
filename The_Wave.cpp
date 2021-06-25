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
bool first_occurence(int *arr, int mid,int x)
{
    if( mid == 0 or arr[mid-1] < x )
        return true;
    else
        return false;
} 
int solution(int *arr, int n,int x)
{
    int low = 0, high = n - 1;
    int mid;
    while(low<=high)
    {
        mid = (low + high) >> 1;
        if(arr[mid] == x)
            return -1;
        else if(arr[mid] < x)
            low = mid + 1;
        else 
        {
              if(first_occurence(arr,mid,x))
                  return mid;
              else
                  high = mid - 1;
        }
    }
    return -2;
} 

int32_t main()
{

    int n, q;
    cin >> n >> q;
    int arr[n];
    fo(i, n)
            cin >>
        arr[i];
    sort(arr, arr + n);
    while(q--)
    {
        int x;
        cin >> x;
        int res = solution(arr, n, x);
        if(res == -1)
            cout << "0" << endl;
        else 
        {
            if(res&1)
                cout << "NEGATIVE" << endl;
            else
                cout << "POSITIVE" << endl;
        }
    } 
    return 0;
}  