#include <bits/stdc++.h>
using namespace std;
const int mod = 1e9 + 7;
int computeHashValue(string &s, int m)
{
    long long ans = 0, base = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        ans += ((s[i] - 'a' + 1) * base) % mod;
        base = (base * 31) % mod;
    }
    return ans % mod;
}
int RabinKarpAlgo()
{
    string s, t;
    cin >> s >> t;
    int count = 0;
    int n = s.length(), m = t.length();
    if (n < m)
        return 0;
    long long hashOfT = computeHashValue(t, m);
    long long hashOfSubString;
    long long maxWeight = 1;
    for (int i = 0; i < m; ++i)
        maxWeight = (maxWeight * 31) % mod;
    for (int i = 0; i <= n - m; ++i)
    {
        if (i == 0)
            hashOfSubString = computeHashValue(s, m);
        else
        {
            hashOfSubString = ((hashOfSubString * 31) % mod - ((s[i - 1] - 'a' + 1) * maxWeight) % mod + (s[i + m - 1] - 'a' + 1) % mod + mod) % mod;
        }
        if (hashOfT == hashOfSubString)
        {
           ++count;
        }
    }
    return count;
}
int main()

{
    cout << RabinKarpAlgo() << endl;
    return 0;
}
