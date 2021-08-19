#include<bits/stdc++.h>
using namespace std;
// given an numbers find the divisors of the number

// if number is perfect square we get duplicates,so use set to find the unique divisors of the number
unordered_set<int> divisors(int n)
{
    unordered_set<int> set;
    for (int i = 1; i <= sqrt(n); i++)
     {  
         if(n%i==0)
         {
             set.insert(i);
             set.insert(n / i);
         }
     }
     return set;
} 
int main() 

{
    int n;
    cin >> n;
    unordered_set<int> set = divisors(n);
    cout << "The divisors of the " << n << " are " << endl;
    for (auto it : set)
        cout << it << " ";

        return 0;

} 