// problem statement
// Given two strings 'str1' and 'str2', check if these two strings are isomorphic to each other.
// Two strings str1 and str2 are called isomorphic if there is a one to one mapping possible for every character of str1 to every character of str2 while preserving the order.
// Note: All occurrences of every character in ‘str1’ should map to the same character in ‘str2’

// Example 1:

// Input:
// str1 = aab
// str2 = xxy
// Output: 1
// Explanation: There are two different
// charactersin aab and xxy, i.e a and b
// with frequency 2and 1 respectively.
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
bool method1(string &s1, string &s2)
{
    int m1[26] = {0};
    int m2[26] = {0};
    if (s1.length() != s2.length())
        return false;
    else
    {
        int i = 0, j = 0;
        while (i < s1.length() and j < s2.length())
        {
            m1[s1[i] - 97]++;
            m2[s2[i] - 97]++;
            if (m1[s1[i] - 97] != m2[s2[i] - 97])
                return false;
            i++;
            j++;
        }
        return true;
    }
}
bool method2(string &s1, string &s2)
{
    unordered_map<char, int> m1, m2;
    if (s1.length() != s2.length())
        return false;
    else
    {

        int i = 0, j = 0;
        while (i < s1.length() and j < s2.length())
        {
            m1[s1[i]]++;
            m2[s2[j]]++;
            if(m1[s1[i]] != m2[s2[j]])
                return false;
            i++;
            j++;
        }
    }
    return true;
}

int32_t main()
{
    // string s1, s2;
    // cin >> s1 >> s2;
    // cout << metod1(s1, s2) << endl;
    string s1 = "saisri";
    cout << 's' + s1 << endl;
    return 0;
} 