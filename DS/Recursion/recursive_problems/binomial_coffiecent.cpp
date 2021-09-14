// we know that ncr = n-1Cr-1 + n-1Cr
// this is the recurrance relation,for given n and r we should calculate the value of nCr
#include <bits/stdc++.h>
using namespace std;
int binomial(int n, int r)
{
    if (r == 0 or r == n) //base condition ,nC0 = 1 and nCn=1
        return 1;
    if(r == 1)
        return n;
    return binomial(n - 1, r - 1) + binomial(n - 1, r);
}
// int binomialmemoziation(int n,int r,unordered_map<int,int> map)
// {
//     if(r==0 or r==n)
//         return 1;
//     if(map[])
//         continue;
//     int n1 = binomialmemoziation(n - 1, r - 1, map);
//     int n2 = binomialmemoziation(n - 1, r, map);
//     map[n1 + n2]++;
//     return n1 + n2;
// } 
int main()

{
    int n, r;
    cin >> n >> r;
    cout<<binomial(n, r)<<endl;

    return 0;
} 