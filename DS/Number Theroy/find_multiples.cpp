// problem statement
// given an array, and given test cases in each test case there are two integers p and q for each test case we should find the numbers which are divisible by p ,q and both p and q
// constraints
// 1<=t<=10^5
// 1<=p,q<=10^5
// i<=A[i]<=10^5

// Approach :
// we will precompute the number of multiples of numbers 1 to 100000 in the array
// that mean for we compute count of array elements that are divisible by 1, and count of array elements that are divisible by 2 and so on
// so from this precomputed array we would find the count of array elements which are divisible by p,and count of array elements which are divisible by q
// and subtract the count of array elements which are divisbile by lcm(p,q) because they are counted twice
// for example:
// let n =5
// array elements are 2 3 6 10
// let p is 2 and q is 3
// multiples of 2 are 2,6,10 so count is 3
// mulitples of 3 are 3,6 so count is 2
// here 6 is counted twice both in 2 and 3 so we will remove the multiples of lcm(p,q)
// multiples of lcm(2,3) i.e 6 are 6 so count is 1
// so answer is 3+2-1 =4

#include <bits/stdc++.h>
using namespace std;

#define N 100001
// this array is for finding the freq of elements in array,that there may be duplicates
// for exmple: 2 2 4 4 9 9 10 here multiples of 2 are 2 2 4 4 10
int freq[N] = {0};
// In this array we will store the count of array elements that are divisible by particular number
// for example multiples[4] mean count of array elements which are divisible by 4
// multiples[10] mean count of array elements which are divisible by 10
int multiples[N] = {0};

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}
int main()
{
    int n;
    cin >> n;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        freq[x]++;
        // storing the frequency of particular number
        // frq[4] mean frequency of 4 in array,and so on
    }
    // using sieve to calculate the count of mulitples in array for each number between 1 to 100000
    for (int i = 1; i < N; i++)
    { //iteratig from 1 to 100000
        for (int j = i; j < N; j += i)
            //   jumping to multiples of i
            // storing the count of multiples in multiples[i]
            // jumping over the muliples of i,and adding it's frequency in array to multiples[i]
            multiples[i] = multiples[i] + freq[j];
    }
    // example
    // suppose array is 2 4 3 6 9 10
    // let N 10
    // so if we take 2, and jump to multiples of 2 i.e 2,4,6,8,10
    // add the frequency of these multiples to muliples[2], if particular multiple of 2 is present then count will increase
    // so multiples[2] = freq[2] + freq[4] + freeq[6] + freq[8] + freq[10]
    // 2,4,6,10 frequency is 1 and 8 frequency is 0,so multiples[2] =4 that mean there are 4 array elements which are divisible by 2

    int p, q, t;
    cin >> t;
    while (t--)
    {
        cin >> p >> q;
        int lcm = (p * q) / gcd(p, q);
        // finding the count of array elements which are divisible by p and q
        int ans = multiples[p] + multiples[q];
        // in some situations lcm may be beyond 10^5 in that cases there is no muliple of lcm which is present in array
        // if lcm is <n then we will subtract the count of array elements which are divisible by lcm(p,q)
        if (lcm < N)
            ans = ans - multiples[lcm];
        cout << ans << endl;
    }

    return 0;
}