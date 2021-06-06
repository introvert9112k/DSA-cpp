// unordered_set is similar to the set,but it is not stored in sortd order 
// insertin,erase,find,takes constant time
// they internally uses the hash maps 
// they have some constraints the data type of the values should be primitive data types like int,float,char,strings because the hashfunctions are not defined for other data types 
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

    unordered_set<int> set;
    set.insert(2);
    set.insert(5);
    set.insert(9);
    // it also does not allow the duplicates 
    cout << "the elements of the set are :" << endl;
    for(auto x : set) 
        cout<<x<<endl;

    set.insert(10); //takes O(1) time
    set.erase(5); //takes O(1) time 
    auto it = set.find(9); //takes O(1) time 
    // unordered set is useful when do not require the order to be maintained 
    return 0;
}   