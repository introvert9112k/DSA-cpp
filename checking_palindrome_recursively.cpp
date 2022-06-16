#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

bool checkpalindrome(int i, string &s, int n)
{
    if (i >= n - 1 - i)
        return true;
    if (s[i] != s[n - 1 - i])
        return false;
    return checkpalindrome(i + 1, s, n);
}
int main()

{
    string s;
    cin >> s;
    int n = s.length();
    if (checkpalindrome(0, s, n))
        cout << "is palindrome" << endl;
    else
        cout << "not a palindrome" << endl;
    return 0;
} 