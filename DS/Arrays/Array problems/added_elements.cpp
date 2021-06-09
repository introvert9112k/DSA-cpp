// problem statement 
// given a string and some characters are added to the string ,and shuffled find the characeters that are added to the string 
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
void added_characters(string s1,string s2)
{
    unordered_map<char, int> m1, m2;
    for (int i = 0; i < s1.length(); i++)
        m1[s1[i]]++;
    for (int i = 0; i < s2.length(); i++)
        m2[s2[i]]++;
    for (int i = 0; i < s2.length(); i++)
    {
        if(m1.find(s2[i])!=m1.end())
        {
            if(m1[s2[i]]!=m2[s2[i]] and m1[s2[i]]!=0)
                {
                    cout << s2[i] << " " << m2[s2[i]] - m1[s2[i]] << endl;
                    m1[s2[i]] = 0;
                } 
        } 
        else
            cout << s2[i] << " " << m2[s2[i]] << endl;
    }
} 
int32_t main()
{

    string s1,s2;
    cin >> s1>>s2;
    added_characters(s1, s2);

    return 0;
} 