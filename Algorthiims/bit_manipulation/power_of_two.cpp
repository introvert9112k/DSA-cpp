// problem statement 
// given a number check whether the number is power of 2 or not 

// Approach 
// There are many approches to check whether the number is power of 2 or not 
// let us explore one by one 

// 1.Method 
// Apply the log2 on the number if the answer is the integer then it is the power of 2 

// 2.Method 
// In the numbers,which are power of 2 there is only one set bit,so find the number of set bits in the number,if set bit count is 1 then it is power of 2 else not 

// Method3 
// we know that the power of 2 contains only 1 set bit and all other bits are unset,and if we subtract the 1 from the power of two we get all bits as set 
// so if we and the power of 2 with the greatest number less than it that mean (num-1) ,then we will get the zero 

// ex 8 = 1000 and 7 is 0111 
// 1000 & 0111 is 0000 
// so if num &  (num-1) = 0 then num is the power of 2 ,this not works for the 0 so the condition becomes if( num  and !(num & (num-1))) 
// if the above condition satisfies then it is the power of 2 
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int,int>>
#define si stack<int> 
#define li list<int> 
#define endl  "\n"  
#define pi pair<int,int> 
#define scan(h) scanf("%lld",&h)
#define st(g,h) scanf("%lld %lld",&g,&h) 
#define print(g) printf("%lld",g) 
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--) 

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
} 
void method1(int n)
{
    ceil(log2(n)) == floor(log2(n)) ? (cout<<"Yes"<<endl) : (cout<<"No"<<endl);
} 
void method2(int n)
{
    int count = 0;
    while(n > 0)
    {
        if(n&1)
            count++;
        n = n >> 1;
    }
    count == 1 ? (cout << "Yes" << endl) : (cout << "No" << endl);
} 
void method3(int n)
{
    n and !(n & (n - 1)) ? (cout << "Yes" << endl) : (cout << "No" << endl);
} 
int32_t main()
{
    int n;
    cin >> n;
    method1(n);

    return 0;
} 