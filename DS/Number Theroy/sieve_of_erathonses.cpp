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
int main() 

{
    int n;
    cin >> n;
    cout << "prime numbers which are less than or equal to  " << n << " is" << endl;
    findprimenumbers(n);

    return 0;
}