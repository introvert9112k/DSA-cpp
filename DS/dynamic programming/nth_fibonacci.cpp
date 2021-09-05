#include<bits/stdc++.h>
using namespace std;
int frecursive(int n)
{
    if(n==0 or n==1)
        return n;
    int n1 = frecursive(n - 1);
    int n2 = frecursive(n - 2);
    return n1 + n2;
} 
// in this fibonacii calculation we repeadtly calculate the value again and again,so we are uncessiarly calculating the that we already calculated,what if we can remember those values and utilize them,
// this is where is dynamic programming comes into picture, remembering the values that are already calculated is known as memoziatio
// let us write effective code for this 
int mfibonacii(int n,int* qb)
{
    if(n==0 or n==1)
        return n;
    if(qb[n] !=0)
        return qb[n];
    int n1 = mfibonacii(n - 1, qb);
    int n2 = mfibonacii(n - 2, qb);
    // here we are remembering the values that are already calculated,in the array qb
    // so this is memoziation
    qb[n] = n1 + n2;
    return n1 + n2;
}  

int tfibonacii(int n)
{  
    // here we are using tabularisation to find the nth fibonacii
    // there two ways we can approach the problem in dp,one is using the memoziation and other is the tabularization
    int dp[n+1];
    dp[0] = 0;
    dp[1] = 1;
    for (int i = 2; i <=n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}
int main() 

{
    int n;
    cin >> n;
    // cout<<frecursive(n)<<endl;
    int qb[n + 1] = {0};
    // cout << mfibonacii(n, qb) << endl;
    cout << tfibonacii(n) << endl;

    return 0;

}  