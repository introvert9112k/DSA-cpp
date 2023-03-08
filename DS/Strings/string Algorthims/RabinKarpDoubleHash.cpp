#include <bits/stdc++.h>
using namespace std;
/*----------------NOTE-------------------------------------
1. See the official Solution of the leetcode problem 28 for explantaion of the code.
*/
pair<long, long> hashValue(string &str, int m)
{
    int radix1 = 26;
    int radix2 = 27;
    int mod1 = 1000000033;
    int mod2 = 1000000007;

    long hash1 = 0, hash2 = 0;
    long factor1 = 1, factor2 = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        hash1 += ((str[i] - 'a') * factor1) % mod1;
        factor1 = (factor1 * radix1) % mod1;
        hash2 += ((str[i] - 'a') * factor2) % mod2;
        factor2 = (factor2 * radix2) % mod2;
    }
    return {hash1 % mod1, hash2 % mod2};
}
int RabinKarpDoubleHash(string &s, string &t)
{
    int radix1 = 26;
    int radix2 = 27;
    int mod1 = 1000000033;
    int mod2 = 1000000007;

    int n = s.length();
    int m = t.length();
    if (n < m)
        return -1;
    long maxWeight1 = 1, maxWeight2 = 1;
    for (int i = 0; i < m; ++i)
    {
        maxWeight1 = (maxWeight1 * radix1) % mod1;
        maxWeight2 = (maxWeight2 * radix2) % mod2;
    }
    auto hashOfT = hashValue(t, m);
    pair<long, long> hashOfSubString;
    for (int i = 0; i <= n - m; ++i)
    {
        if (i == 0)
            hashOfSubString = hashValue(s, m);
        else
        {
            hashOfSubString.first = ((hashOfSubString.first * radix1) % mod1 - ((s[i - 1] - 'a') * maxWeight1) % mod1 + (s[i + m - 1] - 'a') + mod1) % mod1;
            hashOfSubString.second = ((hashOfSubString.second * radix2) % mod2 - ((s[i - 1] - 'a') * maxWeight2) % mod2 + (s[i + m - 1] - 'a') + mod2) % mod2;
        }
        if (hashOfT.first == hashOfSubString.first && hashOfT.second == hashOfSubString.second)
            return i;
    }
    return -1;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << RabinKarpDoubleHash(s, t) << endl;
} 