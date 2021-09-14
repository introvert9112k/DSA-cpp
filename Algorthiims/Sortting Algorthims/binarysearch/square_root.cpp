// in this we will find the square root of the number using binary search

// problem statement
// Given a non-negative integer x, compute and return the square root of x.

// Since the return type is an integer, the decimal digits are truncated, and only the integer part of the result is returned.

// Note: You are not allowed to use any built-in exponent function or operator, such as pow(x, 0.5) or x ** 0.5.

#include <bits/stdc++.h>
using namespace std;
#define int long long

int square(int x)
{
    int low = 1, high = x;
    int mid, ans = 0;
    while (low <= high)
    {
        mid = (low + high) >> 1; //this may cause integer overflow if consider int only
        // to avoid that you can use low + (high-low)/2

        // mid*mid may also overflow so better to use long long instead of int
        // if wish to calculate the cube root of the number,then use mid*mid*mid
        // nth root can be also calculated using binary search
        if (mid * mid <= x)
        {
            ans = mid;
            low = mid + 1;
        }
        else
            high = mid - 1;
    }
    return ans;
}
int main()

{
    int x;
    cin >> x;
    cout << square(x) << endl;

    return 0;
}