// problem statement
// given an array determine the minimum number of swaps required to sort the array
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>

using namespace std;
int main()

{
    int n, count = 0;
    cin >> n;
    int array[n];
    for (int i = 0; i < n; i++)
        cin >> array[i];

    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++)
        v[i] = {array[i], i};

    sort(v.begin(), v.end());

    for (int i = 0; i < n; i++)
    {
        if (v[i].second != i)
        {
            swap(v[i], v[v[i].second]);
            count++;
            i -= 1;
        } 
    } 
    cout << count << endl;
    return 0;
}   