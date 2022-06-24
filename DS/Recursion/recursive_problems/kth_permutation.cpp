#include <bits/stdc++.h>
using namespace std;
/* Brute Force
Find all the permutation recursively, sort the permutations and return k-1th permutation.
 */

class Solution
{
public:
    // source : strivers playlist
    // In each iteration findout the one number in permutation,contine until find out all the numbers
    // Time Complexity : O(N)
    // Space Complexity : O(N) for permutation array
    string getPermutation(int n, int k)
    {
        string ans = "";
        vector<int> p;
        int fact = 1;
        for (int i = 1; i < n; i++)
        {
            fact = fact * i;
            p.push_back(i);
        }
        p.push_back(n);
        k = k - 1;
        while (true)
        {
            ans.push_back(char(48 + p[k / fact]));
            p.erase(p.begin() + k / fact);
            if (p.size() == 0)
                break;
            k = k % fact;
            fact = fact / p.size();
        }
        return ans;
    }
};
int main()

{

    return 0;
}