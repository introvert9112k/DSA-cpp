// find the divisors of all the numbers from 1 to n;
#include <bits/stdc++.h>
using namespace std;
void finddivisors(int n)
{
    vector<int> divisors[n + 1];
    // this is array of vectors
    for (int i = 1; i <= n; i++)
    {
        for (int j = i; j <= n; j += i)
            divisors[j].push_back(i);
    }
    for (int i = 1; i <= n; i++)
    {
        cout << "divisors of " << i << " are  ";
        for (auto divisor : divisors[i])
            cout << divisor << " ";
        cout << endl;
    }
} 
int main()

{
    int n;
    cin >> n;
    finddivisors(n);

    return 0;
} 