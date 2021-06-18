// problem statement 
// iven two numbers x and y, and a range [l, r] where 1 <= l, r <= 32. Find the set bits of y in range [l, r] and set these bits in x also.

// Example 1:

// Input: 
// X = 44, Y = 3 
// L = 1,  R = 5
// Output: 47
// Explaination: presenation of 44 and 3 are 
// 101100 and 11. So in the range 1 to 5 there 
// are two set bits. If those are set in 44 
// it will become 101111 = 47.

// Example 2:

// Input: 
// X = 16, Y = 2
// L = 1,  R = 3
// Output: 18
// Explaination: representation of 16 and 2 
// are 10000 and 10. If the mentioned rule is 
// followed then 16 will become 10010 = 18.
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
void copy_bits_in_range(int x,int y,int l,int h) 
{
    int count = 1;
    while(y > 0)
    {
        if ( (y & 1) and (count >=l) and (count <= h)) 
            x = x | (1 << count - 1);
        else if(count > h)
            break;
        y = y >> 1;
        count++;
    }
    cout << x << endl;
} 

int32_t main()
{

    int x, y;
    cin >> x >> y;
    int l, h;
    cin >> l >> h;
    copy_bits_in_range(x, y, l, h);

    return 0;
} 