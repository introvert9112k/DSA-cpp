// problem statement
// given an array find the all the permutations of the array
#include <bits/stdc++.h>
using namespace std;
// Intution
// We are making sure that every element is at every index 
void permutations(int index, vector<int> &arr)
{
    if (index == arr.size())
    {
        for (auto val : arr)
            cout << val << " ";
        cout << endl;
        return;
    }
    for (int i = index; i < arr.size(); i++)
    {
        swap(arr[index], arr[i]);
        permutations(index + 1, arr);
        swap(arr[index], arr[i]);
    }
}
// T ----- O(n!xn)
// because function calls are made n! times and for each call for loop is running for n times
// S -- O(1)
void permutations(int index, string &str)
{
    if (index == str.length())
    {
        cout << str << endl;
        return;
    }
    for (int i = index; i < str.size(); i++)
    {
        swap(str[index], str[i]);
        permutations(index + 1, str);
        swap(str[index], str[i]);
    }
}
int main()

{
    // // int n;
    // // cin >> n;
    // // vector<int> arr(n);
    // // for (int i = 0; i < n; i++)
    // //     cin >> arr[i];
    // cout << "permutations are : " << endl;
    // permutations(0, arr);

    string str;
    cin >> str;
    cout << "permutations are : " << endl;
    permutations(0, str);
    return 0;
}