// problem statement 
// given two strings find whether the second string is obtained by rotating the first string 

// Algorthim 
// create a temp string that is equal to temp = string1 + string2

// then find whether the string2 is sub string in tmep,if it is then string2 
// is obtained by rotating the string1 else not obtained 
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


int32_t main()
{

    string s1, s2;
    cin >> s1 >> s2;
    string temp = s1 + s2;
    if(temp.find(s2)!= string::npos)
        cout << "the second string is rotation of first string " << endl;
    else
        cout << "the second string is not rotation of the first string " << endl;
    return 0;
} 
