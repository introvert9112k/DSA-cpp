// MMI
// multiplicative mudulo inverse
// suppose lets take a number A and B such that A*B =1
// here b is called the mulitplicatibe inverse of the b
// if (A*B)%M =1 then B is called the modulo mulitplicatibve inverse of A with respective M
// Fermats little theorm
// A^m-1 = 1mod(M) this statement states that the if A^m-1 is divided by m then remainder is 1
// this statement holds only when the m is prime number and A is not multiple of  m
// let us multiple fermats little equation with A^-1 (A inverse ) on both sides then equation becomes
// A^m-2 = A^-1mod(M) so A-1 = (A^m-2)%M hence we got our modulo multiplicative inverse of A
// A^m-2 can be calculated using the binary exponentation

// Note: This A-1 only holds when the m is prime and A is not mulitple of m , in another cases we should use eculid' s extended algorthim to find the mmi
// (A/B)%M = (A%M*B^-1%M)%M in the situation of finding the modulo for a divison we need mmi

// Question:
// There are n students and k toffes we should distribute these k toffes to students such that each student gets one toffee
// the answe is nck = n!/(n-k)!*k!

// let us first precompute the factorials and store them

#include <bits/stdc++.h>
using namespace std;
#define n 1000
#define m 10000007
#define int long long

int fact[n + 1];

int binary(int a, int b, int m1)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a) % m1;
        a = (a * a) % m1;
        b = b >> 1;
    }
    return result;
}
int32_t main()

{
    //  precomputing the factorials
    fact[0] = 1;
    for (int i = 1; i <= n; i++)
        fact[i] = (fact[i - 1] * i) % m;

    //  nck = n!/(n-k)!*k!
    // let us consider n! as A and (n-k)!*k! as B so (A/B)%M = (A%M * B^-1%M)%M;
    int k;
    cin >> k;
    //k must be less than n
    int numer = fact[n]; //here fact of n is n!%m
    cout << "numer" << numer << endl;
    int denom = fact[n - k] * fact[k]; //here denom is b
    cout << "denom" << denom << endl;
    // for this denominator we should find the inverse
    int ans = numer * binary(denom, m - 2, m); //using the binary calculating teh inverse and mulitplying with nuemerator
    cout << ans % m << endl;

    return 0;
}
