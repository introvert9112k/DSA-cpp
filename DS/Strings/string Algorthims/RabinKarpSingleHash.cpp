#include <bits/stdc++.h>
using namespace std;

/*----------------NOTE-------------------------------------
1. See the official Solution of the leetcode problem 28 for explantaion of the code.
See the below youtube video for best explanation.

a -- 1
b -- 2
c -- 3
https://www.youtube.com/watch?v=BQ9E-2umSWc
*/

/*This function returns the hashValue of the provided string*/
int hashValue(string &str, int radix, int mod, int m)
{
    int ans = 0;
    long factor = 1;
    for (int i = m - 1; i >= 0; --i)
    {
        ans += ((int)(str[i] - 'a' + 1) * factor) % mod;
        factor = (factor * radix) % mod;
    }
    return ans % mod;
} 
int RabinKarpAlgo(string &s, string &t)
{
    int n = s.length();
    int m = t.length();
    if (n < m)
        return -1;
    /*Constants*/
    int radix = 26;       /*This is variable
    Mathematically, it turns out that to have a unique hash value for every m-substring, positional weight should be greater than or equal to the number of characters in the set. for the lower case english alphabet take 31 as base,as it is prime and greater than 26(the number of characters in lower case english letters set)
    */
    int mod = 1000000033; /*A large Prime number to minimize the collisons
    larger the prime number lower the collosions.*/
    long maxWeight = 1;
    for (int i = 0; i < m; ++i)
        maxWeight = (maxWeight * radix) % mod;
    /*Computing the hash value of the string t*/
    long hashOfT = hashValue(t, radix, mod, m);
    long hashOfSubString;
    for (int i = 0; i <= n - m; ++i)
    {
        if (i == 0)
            hashOfSubString = hashValue(s, radix, mod, m);
        else
        {
            hashOfSubString = ((hashOfSubString * radix) % mod - ((s[i - 1] - 'a' + 1) * maxWeight) % mod + (s[i + m - 1] - 'a' + 1) + mod) % mod;
        }
        if (hashOfT == hashOfSubString)
        {
            for (int j = 0; j < m; ++j)
            {
                if (t[j] != s[i + j])
                    break;
                if (j == m - 1)
                    return i; /*This returns first index of matching*/
            }
        }
    }
    return -1;
}
int main()
{
    string s, t;
    cin >> s >> t;
    cout << RabinKarpAlgo(s, t) << endl;
} 