// problem statement
// given a bag (knapsack) has some capacity m, that mean it can sustain upto m kg load 
// given set of objects their weights and the profit associated with them when they are sold
// given that the objects are divisible 
// we should find the maximum profit that can achieved by carrying the object in the bag 

// ex:      object1  ob2  ob3  ob4
// profit     20      15  19    32
// weight     10      8   9     5 
// that mean if we sell 10 kg of objec 1 we get 20 rupees profit,if we sell only 5 kg then we will get 10 rupees profit

// for the given case we should find the maximum profit/

// Approach 
// firs calculate the profit/weight ratio for the each object ,and sort in descending order
// include the object first which has the highest profit/weight ratio and add corresponding profit 

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
int gcd(int a,int b)
{
      if(b==0)
          return a;
      return gcd(b,a%b);
}
bool cmp1(pi &p1,pi &p2)
{
    return (double(p1.second) / p1.first) > (double(p2.second) / p2.first); 
} 
double maximumprofit(vector<pi> &v,int m)
{
    sort(v.begin(), v.end(), cmp1);
    int i;
    double profit = 0;
    for (i = 0; i < v.size(); i++)
    {
        if(m >0 and v[i].first<=m)
        {
            m = m - v[i].first;
            profit = profit + double(v[i].second);
        }
        else
            break;
    } 
    if(m > 0 and i<n) 
        profit = profit + (m * v[i].second) / double(v[i].first);
    return profit;
    
} 
int32_t main()
{ 
     
     ios_base::sync_with_stdio(false);
    //  cin.tie(NULL); 
    //  cout.tie(NULL); 
     srand(time(NULL)); 
     int m;
     cout << "enter the capacity of the bag" << endl;
     cin >> m;
     int n;
     cout << "enter the number of objects " << endl;
     cin >> n;
     vector<pi> v(n);
     for (int i = 0; i < n; i++)
     {
         cout << "enter the object " << i + 1 << "weight " << endl;
         cin >> v[i].first;
         cout << "enter the profit associated with this weight" << endl;
         cin >> v[i].second; 
     }
     cout << "maximum profit is : " << maximumprofit(v, m) << endl;
     
     return 0;
}  