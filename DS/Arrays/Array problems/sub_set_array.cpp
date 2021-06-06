// problem statement
// given two arrays arr1 and arr2 we should say whether the arr2 is sub set of the arr1 or not
// it can be done using four methods
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
void method1(int *arr1, int *arr2, int n, int m)
{
    for (int i = 0; i < m; i++)
    {
        int flag = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr2[i] == arr1[j])
                flag = 1;
        }
        if (!flag)
        {
            cout << "the arr2 is not subset of arr1" << endl;
            return;
        }
    }
    cout << "the arr2 is subset of arr1" << endl;

    // time complexity is O(n*m)

    // space complexity is O(1)
}

void method2(int *arr1, int *arr2, int n, int m)
{
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    for (int i = 0; i < m; i++)
    {
        if (!binary_search(arr1, arr1 + n, arr2[i]))
        {

            cout << "arr2 is not a subset of arr1" << endl;
            return;
        }
    }
    cout << "arr2 is subset of arr1" << endl;

    // time complexity is O(nlogn + mlogm + mlogn)

    // as nlogn > mlogn time complexity can also be O(nlogn + mlogm)

    // space complexity is O(1)
}

void method3(int *arr1, int *arr2, int n, int m)
{
    unordered_map<int, int> m1, m2;
    fo(i, n)
        m1[arr1[i]]++;
    fo(i, m)
        m2[arr2[i]]++;
    fo(i, m)
    {
        if (!(m1[arr2[i]] and m2[arr2[i]]))
        {
            cout << "the arr2 is not subset of arr1 " << endl;
            return;
        }
    }
    cout << "the arr2 is subset of arr1" << endl;

    //   time complexity is O(2*m + n)
    //   space complexity is O(m +n )
}

void method4(int *arr1, int *arr2, int n, int m)
{
    sort(arr1, arr1 + n);
    sort(arr2, arr2 + m);
    int i = 0, j = 0,c = 0;
    while (i < m and j < n)
    {
        cout << "sasri" << endl;
        if (arr1[i] == arr2[j])
        {
            i++;
            j++;
            c++;
        }
        else if(arr2[i] > arr1[j] )
            j++;
    } 
    if(c == m)
        cout << "the arr2 is subset of arr1" << endl;
    else
        cout << "the arr2 is not subset of arr1" << endl;
} 

int32_t main() 
{

    int n, m;
    scan(n);
    scan(m);
    int arr1[n], arr2[m];
    fo(i, n)
        scan(arr1[i]);
    fo(i, m)
        scan(arr2[i]);
    method4(arr1, arr2, n, m);
    return 0;
} 