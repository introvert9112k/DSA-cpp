// in this we will look at the code for finding the subsequences of the string 
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
void subsequence(string s,int i,string temp)
{
    if(i == s.length())
      {
          cout << temp << endl;
          return;
      }
      subsequence(s, i+1, temp + s[i]);
      subsequence(s, i+1, temp);
} 
void subsequence2(string &s)
{
    int counter = 1 << s.length();
    for (int i = 1; i < counter; i++)
    {
        for (int j = 0; j < s.length(); j++)
           if(i & (1<<j))
               cout << s[j];
        cout << endl;
    } 
    // refer powerset for explanation
} 
int32_t main()
{

    string s;
    cin >> s;
    subsequence(s,0,"");
    return 0;
} 