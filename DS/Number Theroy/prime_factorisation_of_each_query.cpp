// given a n queries we should find the prime factorisation of the number in each query
// if we iterate over each query and find the prime factorisation using conventional mehtod we time complexity of  O(N*sqrt(n)) this is not desirable time complexity

// we can optimise this approach using the sieve.
#include <bits/stdc++.h>
using namespace std;
#define n 10000000
// spf mean smallest prime factor
int spf[n + 1];

void calculatespf()
{
    // this will calculate the smallest prime factor of all the numbers
    for (int i = 1; i <= n; i++)
        spf[i] = i;
    // let us take an array and intaialize with the values in range
    for (int i = 2; i * i <= n; i++)
    {
        if (spf[i] == i) //this is for checking whether the smallest prime factor of number is alraeady found or not
        // if spf[i]==i then spf is not found,else spf is already marked
        // if spf[i] == i then all the mulitples of this number,has first prime factor as i
        {
            for (int j = i * i; j <= n; j += i)
            {
                if (spf[j] == j) //this mean,till spf is not found,then mark i  as its spf
                    spf[j] = i;
            }
        }
    }
} 
int main()

{

    srand(time(NULL));
    int t;
    cin >> t;
    calculatespf();
    while (t--)
    {
        int k;
        k = rand() % 100 + 1;
        cout << "prime factorisation of the " << k << " is "
             << " ";
        while (k != 1)
        {
            cout << spf[k] << " ";
            k = k / spf[k];
        }
        cout << endl;
    }

    return 0;
}