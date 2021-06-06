// // unordered_map is similar to the map,but in the unordered map the pairs are not arranged in the sorted order
// whenever we don't require the order we can use the unordered map
// internally unordered_maps use the hash tables
// there is constraint on the data type of the key because all the data types does not have pre defined hash functions
// unordered map is constrained to only primitive data types like int,float,double,strings,char
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
void traverse(unordered_map<int, int> &m)
{
    unordered_map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;
}
int32_t main()

{

    // let us declare the unorderd map
    unordered_map<int, int> map;
    map[1] = 2;
    map[2] = 3;
    map[3] = 4;
    cout << "the elements of the unordered map are: " << endl;
    traverse(map);
    // see thease are not sorted
    // all the functions thar applicable on the map are also valid in unordered_map

    // -------------------NOTE-- ---------
    // insertion,acessing,finding,and erasing takes constant time in unordered_map,
    // which is very handy in competitative programming

    map.insert({5, 6});
    cout << "the elements of the unordered map after inserting re : " << endl;
    traverse(map);
    map.erase(3);
    cout << "the elements of unordered map after erasing the key 3 are :" << endl;
    traverse();

    // similarly find function too
    
    return 0;
} 