// problem staatement 
// find the decimal equivalent of the binary number 
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

int binomial_exponentation(int a, int b)
{
    int result = 1;
    while(b > 0)
    {
        if(b&1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
} 
// there is method to find the power of 2 fastly 
// suppose if we want to find the 2 power 3 
// then 1<<3 gives the 2 power 3 
// so whatever we want to find the power left shift the 1 by that many places 
int32_t main()
{

    string binary;
    cin >> binary;
    int decimal = 0;
    int size = binary.length();
    for (int i = size- 1; i >= 0; i--)
    {
        if(binary[i]!= '0')
            decimal += 1 << (size - i - 1);
    }
    cout << "the decimal equivalent of  " << binary << " is : " << decimal;
    return 0;
} 