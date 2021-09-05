// given an number we should find the smallest and highest prime of the number
#include <bits/stdc++.h>
using namespace std;
// we can find it using the sieve for range of numbers
#define n 10
int sieve[n + 1] = {0};
int smallest[n + 1] = {0}; //this stores the smallest prime value of each number in range 1 to n
int highest[n + 1] = {0};  //this sotres the highest prime value of each number in range 1 to n
void smallandhigh()
{
    for (int i = 2; i <= n; i++)
    {
        if (sieve[i] == 0)
        {
            smallest[i] = highest[i] = i; //for a prime number its smallest and highest prime is itself
            for (int j = 2 * i; j <= n; j += i)
            {
                sieve[j] = 1;
                highest[j] = i; //in this highest prime is updating
                if (smallest[j] == 0)
                    //smallest prime is the first prime that divides the given number ,so once the value changes from zero,so we found smallest prime of that number,so we don't need to update it
                    smallest[j] = i;
            }
        }
    }
} 
int main()
{

    smallandhigh();
    for (int i = 2; i < n; i++)
    {
        cout << i << " " << smallest[i] << " " << highest[i] << endl;
    }
    return 0;
}