// map is such a container that it has pairs of values
// the pair consists of key and value ,the keys are unique
// key and value can be of any data type ,map always stores the elements in sorted order based on the key value

// Map internally uses the red black trees

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

void traverse(map<int, int> &m)
{
    map<int, int>::iterator it;
    for (it = m.begin(); it != m.end(); it++)
        cout << it->first << " " << it->second << endl;
    // traversing the map using iterator takes the linear time
    // time complexity is O(N)
}
int32_t main()
{

    // let us define a map
    map<int, int> map;
    // here the key is of int data type and value is of also int data type
    // let us insert the values into the map
    map[1] = 2;
    map[2] = 4;
    map[3] = 5;
    cout << "the key and value pairs of the map are : " << endl;
    traverse(map);
    // insertion in map can be done in two ways
    // first by using the key value,and by the method insert
    map[4] = 8;
    // here first it checks whether the key 4 is present or not,if present then it updates value of key 4,if not present it creates the key in its sorted position and assings the value to it

    // -------------insert method-------------
    map.insert({7, 8});
    // this will insert the 7 in  map if not present ,if present updates the value of the key

    // ---------Time Complexity--------------
    // Time Complexity depend upon the data type of the key

    // if it is the int then insertion takes O(logN) time

    // n is the size of the map at the time of insertion

    // if it is string then it takes "sizeof(string).O(logn)" because for every insertion it should compare the inserting key with the already existing keys,so coomparing the two strings takes O(N) time

    // if the key is of string datatype then it is sorted in lexographic order that mean the strings were arranged as they appear in the dictonary

    // ---------ERasing---------------

    // erase method is used to erase the paritcular key from the map

    // erase functions can takes two types of parameters
    // we can pass the key that we want to delete or the iterator pointing to the key to be deleted
    cout << "the key value pairs of map before erasing a key are : " << endl;
    traverse(map);

    // let us erase the key 3
    map.erase(3);
    cout << "the key value pairs of map after deleting the key 3 is : " << endl;
    traverse(map);

    // time complexity of the erase also depends upon the key data type /
    // for int it is O(logn)
    // for string it is sizeof(string)*logn

    // ------------Find-----------
    // find checks whether the given key is present in the map or not, if present it returns the iterator pointing to particular location or else returns the end()

    // lets check the key 4
    auto it = map.find(4);
    if (it != map.end())
        cout << "the key 4 is present in map" << endl;
    else
        cout << "the key 4 is not present in map" << endl;

    // fetching the value from map using the key also depends upon the datatype of key
    cout << map[2] << endl;
    // this takes the logn time

    // NOte :
    // so be careful about the data type of key while using the map
    return 0;
} 