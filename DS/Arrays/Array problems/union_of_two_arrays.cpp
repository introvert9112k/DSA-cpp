// problem statement
// Given two arrays a[] and b[] of size n and m respectively. The task is to find union between these two arrays.

// Union of the two arrays can be defined as the set containing distinct elements from both the arrays. If there are repetitions, then only one occurrence of element should be printed in union.

// return the size of the union array

// Approach 1

// first define a set and insert the elements from the both the arrays into set ,as set does not contains the duplicate elements so the set becomes the union array
// time complexity is O(nlogn + mlogm) as inserting takes logn time,inserting n and m elements take nlogn+mlogm time

// Approach 2
// define a map,and insert the elements into map , the map elements are unique so it becomes the union array

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
#define s(n) scanf("%d", &n)
#define st(n, m) scanf("%d %d", &n, &m)
#define p(n) printf("%d", n)
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
void set_method(int *a, int *b, int n, int m)
{
    set<int> q;
    for (int i = 0; i < n; i++)
        q.insert(a[i]);
    for (int j = 0; j < m; j++)
        q.insert(b[j]);
    cout << q.size() << endl;
}
void unordered_map_method(int *a, int *b, int n, int m)
{
    unordered_map<int,int> map;
    fo(i, n)
        map[a[i]]++;
    fo(i, m)
        map[b[i]]++;
    cout << map.size() << endl;
} 

int32_t main()
{
    int n, m;
    cin >> n >> m;
    int a[n], b[m];
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int j = 0; j < m; j++)
        cin >> b[j];
    // set_method(a, b, n, m);
    // unordered_map_method(a, b, n, m);
    unordered_map<int, int> map;
    fo(i, n)
        map[a[i]]++;
    cout << map[1] << endl;
    return 0;
} 