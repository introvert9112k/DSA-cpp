// in this we will calculate the ncr value using the recursion 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void ncr_iterative(int n, int r,int &n_fact, int &nr_fact, int &r_fact)
{
    int fact = 1;
    for (int i = 1; i <= n; i++)
    {
        fact = fact * i;
        if(i == r)
            r_fact = fact;
        if (i == n-r)
            nr_fact = fact;
    }
    n_fact = fact;
} 
int nCr_recur(int n,int r)
{
    
    return r == 0 or n == r ? 1 : nCr_recur(n - 1, r - 1) + nCr_recur(n - 1, r);
} 

// the  value of nCr is equal to sum of the n-1Cr-1 and n-1Cr 
//  nCr = n-1Cr-1 + n-1Cr -----------recurrence relation 
    //  if r==0 or n ==r then it is 1  ------base condition
    // these two can be obtained from the pascals traingle 
int main() 

{
    int n, r,n_fact,nr_fact,r_fact,nCr;
    cin >> n >> r;
    ncr_iterative(5, 3, n_fact, nr_fact, r_fact);
    nCr = n_fact / (r_fact * nr_fact);
    cout << "the nCr value using iterative is : " << nCr << endl;
    cout << "the nCr value using recursion is : " << nCr_recur(n, r) << endl;
    return 0;
    
} 