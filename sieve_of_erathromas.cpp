// it is algorthim for finding the prime numbers betweent that are smaller than or equal to the given number

// The sieve of Eratosthenes is one of the most efficient ways to find all primes smaller than n when n is smaller than 10 million or so

// Let us take an example when n = 50. So we need to print all prime numbers smaller than or equal to 50.
// We create a list of all numbers from 2 to 50.

// According to the algorithm we will mark all the numbers which are divisible by 2 and are greater than or equal to the square of it.

// ow we move to our next unmarked number 3 and mark all the numbers which are multiples of 3 and are greater than or equal to the square of it.

// We move to our next unmarked number 5 and mark all multiples of 5 and are greater than or equal to the square of it.

// We continue this process and our final values that left in the array is prime numbers

#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>
using namespace std;
void seive_of_erathromas(int *array, long long int n)
{
  //   odd numbers can be prime numbers so first we will make the odd places values as 1 and check them only for prime
  for (long long int i = 3; i <= n; i += 2)
    array[i] = 1;

  for (long long int i = 3; i <= sqrt(n); i++)
  {
    if (array[i] == 1)
    {
      for (long long int j = i * i; j <= n; j += i)
        array[j] = 0;
    }
  }

  array[2] = 1;
  cout << "the prime numbers that are less than are equal to  " << n << " are : " << endl;
  cout << "2"
       << " ";
  for (long long int k = 3; k <= n; k += 2)
  {
    if (array[k] == 1)
      cout << k << " ";
  }
}
int main()

{
  long long int n;
  cin >> n;
  // let us create the array of that size and intialise all the values to zero
  int array[n] = {0}; // intializing all the array element to zero
  seive_of_erathromas(array, n);
  return 0;
}

// the value of n should be around  500000