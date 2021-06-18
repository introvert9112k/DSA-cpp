// in this we will see different ways of finding the all the substrings of a string
#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
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
void string1(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i ; j < s.length(); j++)
        {
            for (int k = i; k <= j; k++)
                cout << s[k];
            cout << endl;
        }
    }
    // time complexity is O(N^3)
}  
void using_substr(string &s)
{
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = 1; j <= s.length() - i; j++)
            cout << s.substr(i, j) <<endl;
    }
    // sub_str takes two arguments,one is the starting position and another is the ending position
    // substr function returns a string in range start, end - 1
    // s.substr(i,j) mean it returns the string from i to j-1 
} 
void string3(string &s)
{
    string temp = "";
    for (int i = 0; i < s.length(); i++)
    {
        for (int j = i; j < s.length(); j++)
            {
                temp += s[j];
                cout << temp << endl;
            }
            temp = "";
    } 
    // Time O(N^2)
    // Space O(maxsize of string)
}  

int32_t main()
{
    string s;
    cin >> s;
   string3(s);
    return 0;
} 