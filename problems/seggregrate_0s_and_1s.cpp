#include <bits/stdc++.h>
using namespace std;

int main()

{
    vector<int> arr = {0, 1, 0, 1, 0, 0, 1, 1, 1, 0};
    int n = arr.size();
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && arr[i] == 0)
            i++;
        while (i < j && arr[j] == 1)
            j--;
        swap(arr[i], arr[j]);
    }
    for (auto &val : arr)
        cout << val << " ";

    return 0;
} 