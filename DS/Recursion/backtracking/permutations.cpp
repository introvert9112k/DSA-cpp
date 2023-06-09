// problem statement
// given an array find the all the permutations of the array
#include <bits/stdc++.h>
using namespace std;
// Intution
/*We are making sure that every element is at every index.
In the previous approach we used the visited to find the numbers which 
can be current position.If we observer carefully if we are index i in the 
current Permutation, the numbers from [0,i-1] already be in the permutaion.
So left over numbers is [i,n-1].
So for the current index i,the possible numbers at current index is [i,n-1].
So we no longer needed visited array to find the valid numbers at this position.

For the index i,swap this number with indexes [i-n-1] to get numbers at that
indexes to current index, after processing is done we can swap them again to 
bring back to their original postion.

NOTE : In this we are changing the original array in recursion calls.
When the recursion compelets our array would be back to original state.

TC : O(n!xn)
There are n! permutations,so the last level of the recursive tree has n! nodes.
And we are storing/printing the permutation which also takes O(n)
So Total Recursion calls is (n!xn)
SC : O(1)
*/
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