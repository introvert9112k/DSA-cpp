// given a number find the prime factorisation of the number
#include <bits/stdc++.h>
using namespace std;
// this is how we find the prime factorisation in elementary school ,first takes the smallest prime that divides the number and divides it until it is not divisible by that prime,then go for next prime

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

    NOTE:
    // prime factors of the number will be always less than or equal to sqrt(n) except the number itself
    // maximum number of prime factors of a number is equal to log2(N)
} 
int main()

{
    int t;
    cin >> t;
    srand(time(NULL));
    while (t--)
    {
        int n;
        n = rand() % 1000;
        cout << "prime factorisation of the " << n << " is : ";
        primefactorisation(n);
        cout << endl;
    }
    return 0;
}