#include <bits/stdc++.h>
using namespace std;

string addStrings(string &x, string &y, int n)
{
    // Write your code here.
    string ans;
    for (int i = 0; i < n; i++)
    {
        int z = ((x[i] - 'a') + (y[i] - 'a')) % 26;
        ans.push_back(char('a' + z));
    }
    cout << ans << endl;
    return ans;
}
int main()

{
    string x = "cpgjplitxe", y = "uoqqaeqwkk";
    addStrings(x, y, 10);
    return 0;
} 