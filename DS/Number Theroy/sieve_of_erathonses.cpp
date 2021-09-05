// in this we will look at the sieve of erathoenses
#include <bits/stdc++.h>
using namespace std;

void findprimenumbers(int n)
{
    vector<int> arr(n+1,true);
    for (int i = 2; i * i <= n; i++)
    {
        if (arr[i])
        {
            for (int j = i * i; j <= n; j += i)
                arr[j] = false;
        }
    }

    for (int i = 2; i <= n; i++)
        if (arr[i])
            cout << i << " ";
} 
// Time complexity is o(n*log(log(N)))

// Another approach for finding sieve
void findprimes2(int n)
{
    vector<bool> arr(n + 1, true);
    for (int i = 2; i <= n; i++)
    {
        if(arr[i])
        {
            for (int j = 2 * i; j <= n; j+=i)
                arr[j] = false;
        }
    }
    cout << "prime numbers are " << endl;
    for (int i = 2; i <= n; i++)
       if(arr[i])
           cout << i << " ";
    // Time complexity is 
    // here code will run for n/2 + n/3 +n/4 + n/5................1
    // taking n common n(1/2+ 1/3 + 1/4 + 1/5 + ............) the term in bracket corresponds to logN 
    // hence the code will run for O(NlogN) times
    // this is bit slow compared to previous but works fine for size in the range of 10e7
}  
int main() 

{
    int n;
    cin >> n;
    cout << "prime numbers which are less than or equal to  " << n << " is" << endl;
    findprimes2(n);

    return 0; 
}