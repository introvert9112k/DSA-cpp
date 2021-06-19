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
void alternative_pos_neg(int *arr, int n)
{
    int pivot = 0,m=0;
    int temp[n];
    //partition Algorthim
    for (int i = 0; i < n; i++)
    {
        if(arr[i] < pivot)
        {
            swap(arr[i], arr[m]);
            m++;
        }
    } 
    // Actual code
    int j = n - 1, i = 0, count = 0,k=0;
    while(i <= j)
    {
         if(!(count & 1))
         {
             temp[k] = arr[i];
             i++;
             k++;
             count++;
         }
         else 
         {
             temp[k] = arr[j];
             j--;
             k++;
             count++;
         }
    } 
    fo(i, n)
    cout<< temp[i] << " ";
    Time complexity O(N)
    space complexity O(N) 
}  

int32_t main()
{

    int n;
    cin >> n;
    int arr[n];
    fo(i, n)
     cin >>arr[i];
    alternative_pos_neg(arr, n);
    return 0;
} 