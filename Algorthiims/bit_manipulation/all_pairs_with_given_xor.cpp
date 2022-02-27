#include <bits/stdc++.h>
using namespace std;

void findpairs(int a, int b, int i, int msb, int x, set<pair<int, int>> &set)
{
    // if ((a && floor(log2(a)) == msb) || (b && floor(log2(b)) == msb))
    // {
    //     set.insert({min(a, b), max(a, b)});
    //     return;
    // }
    if (i > 31)
        return;
    if ((a ^ b) == x)
    {
        cout << a << " " << b << endl;
        return;
    }
    if (x & (1 << i))
    {
        findpairs(a | (1 << i), b, i + 1, msb, x, set);
        findpairs(a, b | (1 << i), i + 1, msb, x, set);
    }
    else
    {
        findpairs(a, b, i + 1, msb, x, set);
        findpairs(a | (1 << i), b | (1 << i), i + 1, msb, x, set);
    }
}

int main()

{
    int x;
    cin >> x;
    int msb = log2(x);
    set<pair<int, int>> set;
    findpairs(0, 0, 0, msb, x, set);
    cout << "pairs with given xor value " << x << " are " << endl;
    for (auto &pair : set)
        cout << pair.first << " " << pair.second << endl;
    cout << endl;
    return 0;
}
