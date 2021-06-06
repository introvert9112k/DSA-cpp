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
     
    //  multiset is similar to the set ,but multiset allows the duplicates 
    // insertion,erase,find takes logn time
    multiset<int> set;
    set.insert(2);
    set.insert(4);
    set.insert(5);
    set.insert(2);
    set.insert(5);
    cout << "the elements of the multiset are : " << endl;
    // see that the set has duplicate elements and sorted
    for(auto x : set)
        cout<<x<<endl;
    // insertion ,erase ,find works similar to that of in the set /
    // multiset also uses the red black trees internally 

    // in case of erase function, iterator as parameter to the erase will erase only the that particular value,and does not erase it duplicates,whereas the erase function with value as parameter deletes all the occurances of the value in the set 

//    take care of erase function while using the multiset container
    // auto it = set.find(2);
    // set.erase(it);
    // cout << "the elements of the set after deleting the 2 using iterator is : " << endl;
    // for(auto x : set) 
    //     cout<< x <<endl;

    set.erase(5);
    cout << "the elements of set after deleting the 5 using the value are :" << endl;
    for(auto x : set)
        cout<<x<<endl;
    // notice that in first case only the first occurence of the 2 is deleted and in second case all the occurences of the 5 are deleted 
    return 0;
} 