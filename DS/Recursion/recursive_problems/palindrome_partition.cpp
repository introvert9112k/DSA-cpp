#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    // Source : strivers playlist

    /*Function to check whether the provided string is palindrome or not.*/
    bool ispalindrome(string &temp)
    {
        int i = 0, j = temp.length() - 1;
        while (i < j)
            if (temp[i++] != temp[j--])
                return false;
        return true;
    }

    /*checking out all the possiblites*/
    void palindrome_partition(int ind, string &s, vector<vector<string>> &ans, vector<string> &path)
    {
        if (ind == s.length()) /*If we sucessfully reached end, then found a valid partition*/
        {
            ans.push_back(path);
            return;
        }
        for (int i = ind; i < s.length(); i++)
        {
            string temp = s.substr(ind, i - ind + 1);
            if (ispalindrome(temp))
            {
                path.push_back(temp);
                palindrome_partition(i + 1, s, ans, path);
                path.pop_back();
            }
        }
    }

    /*Driving Code*/
    vector<vector<string>> partition(string s)
    {
        vector<vector<string>> ans;
        vector<string> path;
        palindrome_partition(0, s, ans, path);
        return ans;
    }
};
int main()
{
    return 0;
} 