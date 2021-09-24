#include<bits/stdc++.h>
using namespace std;
// problem statement
// given an n, find the set bits count from 1 to n

// there is a pattern for setbit counts from 1 to n

// bruteforce approach using binary exponentation
int countsetbits1(int n) 
{
    int x;
    int ans=0, count;
    for (int i = 1; i <= n; i++ )
    {
        x = i;
        count = 0;
        while(x >0)
        {
            if(x&1)
                count++;
            x = x >> 1;
        }
        ans += count;
    }
    return ans;
} 


// using kahanes algorthim
int countsetbits2(int n)
{
    int x;
    int ans = 0, count;
    for (int i = 1; i <= n; i++)
    {
        x = i;
        count = 0;
        while(x > 0)
        {
            int rsbm = x & -x;
            x = x - rsbm;
            count++;
        }
        ans += count;
    }
    return ans;
} 
// most optimised approach
int countsetbits(int n)
{
    if(n ==0)
        return 0;
    int x = log2(n);
    int bitsuptox = x * (1 << x - 1);
    int msbxton = n - (1 << x) +1;
    return bitsuptox + msbxton + countsetbits(n - (1 << x));
} 
// reference:
// https://www.youtube.com/watch?v=g6OxU-hRGtY&t=754s&ab_channel=Pepcoding

int main() 
{

    int n;
    cin >> n;
    cout<<countsetbits2(n)<<endl;
    return 0;

} 