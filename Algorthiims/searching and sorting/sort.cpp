// in this we will look at different ways of sorting vectors
#include <bits/stdc++.h>
using namespace std;

void print(vector<int> &v)
{
    for (auto it : v)
        cout << it << " ";
    cout << endl;
}
void printpair(vector<pair<int, int>> &v)
{
    for (auto it : v)
        cout << "{" << it.first << "," << it.second << " }"
             << " ";
    cout << endl;
}
bool cmp1(pair<int, int> a, pair<int, int> b)
{
    return a.first < b.first;
}
bool cmp2(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
bool cmp3(pair<int, int> a, pair<int, int> b)
{
    return a.first > b.first;
}
bool cmp4(pair<int, int> a, pair<int, int> b)
{
    return a.second > b.second;
}
int main()

{
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    // thi will sort the vector in increasing order
    cout << "Elements in ascending order: " << endl;
    sort(v.begin(), v.end());
    print(v);
    // if we want to sort the vector in the descending order,we can use comparator or buit in comparator greater<int>() sorting in decreasing order

    // or we can use the rbegin() and rend() sorting the vector in incresing order from last elements,increasing from end is equal to the decreasing from start, so vector will be sorted in descending order
    cout << "Elements in descending order using rbegin() and rend() " << endl;
    sort(v.rbegin(), v.rend());
    print(v);
    cout << "Elements in descendign order user built in compartor " << endl;
    sort(v.begin(), v.end(), greater<int>());
    print(v);

    // if there is any other data types other than primitive data types use the compartor for sorting
    // let us sort the vector of pairs, in ascending,descending orders based on the first value and second value

    int p, x;
    cin >> p;
    vector<pair<int, int>> k(p);
    for (int i = 0; i < p; i++)
    {
        cin >> x;
        k[i] = {x, i};
    }
    cout << "Increasing order based on the first value : " << endl;
    sort(k.begin(), k.end(), cmp1);
    printpair(k);
    cout << "Increasing order based on the second values : " << endl;
    sort(k.begin(), k.end(), cmp2);
    printpair(k);
    cout << "Decreasing order based on the first value : " << endl;
    sort(k.begin(), k.end(), cmp3);
    printpair(k);
    cout << "Decreasing order based on the second value : " << endl;
    sort(k.begin(), k.end(), cmp4);
    printpair(k);

    // use compartors for all data types except primitve data types,we can use compartors for primitive types too,but already comparotor is used by sorting primitve data types, so need to give compartor explicitly
    return 0;
} 