// link https://www.codechef.com/submit/GCDDIV

#include <bits/stdc++.h>
using namespace std;
#define int long long
#define endl "\n"

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
bool check(int a, int k)
{
    int max_prime = 1;
    for (int i = 2; i * i <= a; i++)
    {
        while ((a % i) == 0)
        {
            a = a / i;
            max_prime = max(max_prime, i);
        }
    }
    max_prime = max(max_prime, a);
    return max_prime <= k;
}
bool findgcd(vector<int> &v, int k)
{
    if (v.size() == 1)
        return v[0] <= k;
    int x = gcd(v[0], v[1]);
    for (int i = 2; i < v.size(); i++)
        x = gcd(x, v[i]);
    // cout << x << endl;
    // for(auto it : v)
    //     cout << it / x << " ";
    // cout << endl;
    return check(x, k);
}

int32_t main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        // n = rand() % 10 + 1;
        // k = rand() % 10 + 1;
        // cout << n << " "<< k << " "<<endl;
        vector<int> v(n);
        for (int i = 0; i < n; i++)
            cin >> v[i];
        // v[i] = rand() % 100;
        // for(auto it : v)
        //     cout << it << " ";
        // cout << endl;
        if (findgcd(v, k))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        // cout << endl;
    }
} 
