// problem statement
// find the common elements in the three sorted arrays
#include <bits/stdc++.h>
#define int long long
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
void method1(int *a1, int *a2, int *a3, int n, int m, int k)
{
    unordered_map<int, int> m1, m2, m3;
    vector<int> v;
    fo(i, n)
        m1[a1[i]]++;
    fo(i, m)
        m2[a2[i]]++;
    fo(i, k)
        m3[a3[i]]++;
    fo(i, n)
    {
        if (m1[a1[i]] and m2[a2[i]] and m3[a3[i]])
        {
            v.push_back(a1[i]);
            m1[a1[i]] = 0;
        }
    }
    for (auto x : v)
        cout << x << " ";
}
void method2(int *a1,int* a2,int* a3,int n,int m,int p)
{
    int i = 0, j = 0, k = 0;
    vector<int> v;

    while(i < n and j < m and k < p)
    {
        
        if(a1[i] == a2[j] and a2[j] == a3[k]) 
        {
            v.push_back(a1[i]);
            i++;
            j++;
            k++;
        }
        else if(a1[i] < a2[j])
            i++;
        else if(a2[j] < a3[k] )
            j++;
        else
            k++;
        while (i > 0 and i < n and a1[i-1] == a1[i])
            i++;
        while (j> 0 and j < m and a2[j-1] == a2[j])
            j++;
        while (k > 0 and k < n and a3[k-1] == a3[k])
            k++;
        
    }
    for(auto x : v)
        cout<< x <<" ";
} 
int32_t main()
{

    int n, m, k;
    scan(n); 
    scan(m);
    scan(k);
    int a1[n], a2[m], a3[k];
    fo(i, n)
        scan(a1[i]);
    fo(i, m)
        scan(a2[i]);
    fo(i, k)
        scan(a3[i]);
    method2(a1, a2, a3, n, m, k);
    return 0;
}
