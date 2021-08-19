// in this we will look at the segmented sieve
// in the sieve of erathonses there is a limit of the array size, maximum array size that we can create is 10^7
// in case of calculating the prime numbers in a largere range than 10^7 it would become problem ,this can avoided by using the segemented sieve. in this we take only segment of teh sieve array whcih we require
#include <bits/stdc++.h>
#define n 10000000
using namespace std;
// let us first find the prime numbers whcih are in the range 10^7

int sieve[n + 1] = {0};
// here we are calculating prime numbers form range 1 to 10^7 ,and from this we are getting our desired prime numbers in the range 1 to r

// we can directly find the primes in range 1 to r,but if there are many test cases,for each test case we seperatedly find the primes, this can be reduced by precomputation of primes for maximum range
void findsieve()
{
    for (int i = 2; i * i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            for (int j = i * i; j <= n; j += i)
                sieve[j] = 1;
        }
    }
}
vector<int> primenumbers(int r)
{
    vector<int> v;
    for (int i = 2; i <= r; i++)
        if (sieve[i] == 0)
            v.push_back(i);
    return v;
}
int main()

{
    // we have to find the prime numbers in the range l to r
    // steps
    // 1.first we find the prime numbers which are less than the sqrt of r
    // 2.we mark the multiples of these primes in the range l to r
    // 3.the unmarked numbers in the range l to r is the prime numbers in the range
    findsieve();
    int l, r;
    cin >> l >> r;
    vector<int> primes = primenumbers(r);
    // we got the primes which are less than the r
    // now create a array as we do in the sieve for marking the multiples of primes
    int dummy[r - l + 1] = {0};
    for (auto prime : primes)
    {
        int firstmultiple = (l / prime) * prime; // this is formula to calculate first multiple of prime in range

        // first multiple is nothing but the least number in the range which is multiple of the given prime
        // from that firstmultiple we add prime repeadtly and mark the all the multiples of that prime in the range
        // sometimes we could directly jump to the square of the prime if it is present in the range, in this case when square of prime is presented in range,the first multiple would be already marked as we see in the sieve of erathonses, so need of again iterating from the first multiple so jump to square of prime

        // so we take maximum of the first multiple and square
        if (firstmultiple < l)
            firstmultiple += prime;
        // if first multiple is less then we add corresponding prime to that

        // we can directly start from the firstmuliple instead of square too,it also gives same answer,but we unnecessarily will iterate
        for (int i = max(firstmultiple, prime * prime); i <= r; i += prime)
        {
            dummy[i - l] = 1;
        }
    }
    cout << "the prime numbers between the range " << l << " " << r << " are " << endl;
    for (int i = 0; i < (r - l + 1); i++)
    {
        if (dummy[i] == 0)
            cout << i + l << " ";
    }
    return 0;
    // segmented sieve is generally used when the range is lareger than the 10^7 because max array size is only 10^7
}