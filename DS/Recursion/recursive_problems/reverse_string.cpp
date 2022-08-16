#include <bits/stdc++.h>
using namespace std;

bool palindromeCheck(string &s, int i, int n)
{
    if (s[i] != s[n - i - 1])
        return false;
    if (i > n - i - 1)
        return true;
    return palindromeCheck(s, i + 1, n);
}
int main()

{
    string s;
    cin >> s;
    string ans = palindromeCheck(s, 0, s.length()) ? "isPalindrome" : "notPalindrome";
    cout << ans << endl;
    return 0;
} 