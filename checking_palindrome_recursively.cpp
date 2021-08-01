#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
bool palindrome(string original, int n)
{
    static int cnt = 0;
    if (cnt < n/2)
    {
        if (original[cnt] != original[n - cnt - 1])
            return false;
        cnt++;
        return palindrome(original, n);
    }
    return true;
}

int main()

{
    string original;
    cin >> original;
    if (palindrome(original, original.length()))
        cout << original << "  is pallindrome" << endl;
    else
        cout << original << " is not palindrome" << endl;
    return 0;
} 