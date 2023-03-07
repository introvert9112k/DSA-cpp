// given a number find the prime factorisation of the number
#include <bits/stdc++.h>
using namespace std;
// this is how we find the prime factorisation in elementary school ,first takes the smallest prime that divides the number and divides it until it is not divisible by that prime,then go for next prime.

/*1. We utilize the fact that the smallest divisor of the any number excluding 1 as divisor, is a prime number.
2.We find the smallest divisor of a number i.e prime and keeping dividing the number until is divisible by that divisor.
3.For the new value of n,the divisors found so for doesn't divide it, if it divides it then we won't get current value of n. 
4.So need not to bother about the divisors encountered so for,We can safely say that the first divisor of the modified n is not encounterd so far.
5.The first prime factor of a composite number is always <= sqrt(number).So to find the first prime factor of a number we can iterate until it's square root.
5.The above statement not holds in case of the prime number. For a prime number there is no divisor which is prime less than it's sqrt. So there may be cases where the modified value of n may be the prime, In that scenario there would be no prime divisor less than the sqrt of number so the for loop stops.
6.So we should explictly check whether the n becomes 1 at last or not. If n > 1,that mean we ecountered a prime number in the process.So take it.*/

// this is how this prime factorisation works
void primefactorisation(int n)
{
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            cout << i << " ";
        }
    }
    // we go on divide n until it becomes 1,in some cases it is may possible that n does not becomes 1,in that situation the final value of n would be also a prime, so print it
    if (n != 1)
        cout << n << " ";

// NOTE:
    // prime factors of the number will be always less than or equal to sqrt(n) except the number itself
    // maximum number of prime factors of a number is equal to log2(N)
    // time complexity is O(sqrt(N))/
    // this can be reduced to logN using the sieve
} 

// counting the number of even and odd prime factors of the number
void count(int n)
{
    int even = 0, odd = 0;
    for (int i = 2; i * i <= n; i++)
    {
        while (n % i == 0)
        {
            n = n / i;
            i & 1 ? ++odd : ++even;
        }
    }
    if (n != 1)
        n & 1 ? ++odd : ++even;
    cout << "odd factors count is" << odd << endl;
    cout << "even factors count is " << even << endl;
} 

int main()

{
    int t;
    cin >> t;
    srand(time(NULL));
    while (t--)
    {
        int n;
        cin >> n;
        cout << "prime factorisation of the " << n << " is : ";
        primefactorisation(n);
        // count(n);
        cout << endl;
    }
    return 0;
} 