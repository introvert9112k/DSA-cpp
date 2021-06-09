// problem statement 
// Split the binary string into substrings with equal number of 0s and 1s

// Approach: Initialize count = 0 and traverse the string character by character and keep track of the number of 0s and 1s so far, whenever the count of 0s and 1s become equal increment the count. As in the given question, if it is not possible to split string then we must not have any sub string having equal number of 0’s and 1’s on that time count = 0 then return -1 else print the value of count after the traversal of the complete string.

// / C++ implementation of the approach/
#include <bits/stdc++.h>
using namespace std;
 
// Function to return the count
// of maximum substrings str
// can be divided into
int maxSubStr(string str, int n)
{
 
    // To store the count of 0s and 1s
    int count0 = 0, count1 = 0;
 
    // To store the count of maximum
    // substrings str can be divided into
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if (str[i] == '0') {
            count0++;
        }
        else {
            count1++;
        }
        if (count0 == count1) {
            cnt++;
        }
    }
 
    // It is not possible to
    // split the string
    if (cnt == 0) {
        return -1;
    }
 
    return cnt;
}
 
// Driver code
int main()
{
    string sai;
    cin >> sai;
    int n = sai.length();

    cout << maxSubStr(str, n);
 
    return 0;
}  