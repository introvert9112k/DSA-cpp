#include <bits/stdc++.h>
using namespace std;

void combinations(int index, vector<int> &arr, vector<int> &ds, int target)
{
    if (index == arr.size() or target == 0)
    {
        if (target == 0)
        {
            for (auto val : ds)
                cout << val << " ";
            cout << endl;
        }
        return;
    }
    if (arr[index] <= target)
    {
        ds.push_back(arr[index]);
        combinations(index + 1, arr, ds, target - arr[index]);
        ds.pop_back();
    }
    if (arr[index+1] != arr[index]) 
        combinations(index + 1, arr, ds, target);
    else if()
} 

int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int target;
    cout << "enter the target" << endl;
    cin >> target;
    sort(arr.begin(), arr.end());
    vector<int> ds;
    combinations(0, arr, ds, target);
    return 0;
}