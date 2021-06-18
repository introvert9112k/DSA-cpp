// Input: Set[], set_size
// 1. Get the size of power set
//     powet_set_size = pow(2, set_size)
// 2  Loop for counter from 0 to pow_set_size
//      (a) Loop for i = 0 to set_size
//           (i) If ith bit in counter is set
//                Print ith element from set for this subset
//      (b) Print separator for subsets i.e., newline
// Example: 
 

// Set  = [a,b,c]
// power_set_size = pow(2, 3) = 8
// Run for binary counter = 000 to 111

// Value of Counter            Subset
//     000                    -> Empty set
//     001                    -> a
//     010                    -> b
//     011                    -> ab
//     100                    -> c
//     101                    -> ac
//     110                    -> bc
    // 111                    -> abc
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
void powerset(string &s,int counter)
{
    for (int i = 1; i < counter; i++)
    {
        int b = i, count = 0;
        while(b > 0)
        {
            if(b&1)
            {
                cout << s[count];
                
            }
            count++;
            b = b >> 1;
        } 
        cout << endl;
        
    }

}  
int32_t main()
{

    string s;
    cin >> s;
    int counter = 1 << (s.length());
    powerset(s,counter);
    return 0;
    
} 