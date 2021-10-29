#include <bits/stdc++.h>
using namespace std;
// problem statement
// given a string we should find the length of the largest substring without repeating characters

int solve(string &s)
{
    int left = 0, right = 0, length = 0;
    int n = s.length();
    unordered_set<char> set;
    while (right < n)
    {
        if (set.find(s[right]) != set.end())
        {
            set.erase(s[left]);
            left++;
        }
        else
        {
            length = max(right - left + 1, length);
            set.insert(s[right]);
            right++;
        }
    }
    return length;
    //  T - O(2N) because left and right moves n times in worst cas
    // space - O(N) if all characters in string are unique
}

// same approach using map instead of set
// same time and space complexites
int solve1(string &s)
{
    int left = 0, right = 0, length = 0;
    int n = s.length();
    unordered_map<char, int> map;
    while (right < n)
    {
        if (map.find(s[right]) != map.end())
        {
            map[s[right]]--;
            if (map[s[right]] == 0)
                map.erase(s[right]);
            left++;
        }
        else
        {
            length = max(right - left + 1, length);
            map[s[right]]++;
            right++;
        }
        // suppose in "abcabcbb" we smoothly move until the abc after that we encounter the
        // duplicate a, so we should remove it from our present substring so we move the i to one place that is to 1st position so now i is pointing to 1st and j is pointing to 3rd
    }
    return length;
}

// ------------optimised approach---------------
// T - o(N)
// S - O(N)

// In the previous approach if we find any duplicate we are iterating through characters between left and right,and removing the characters until the duplicate is removed,and after that moving forward

// If we can store the last occurence of the characters,then we can directly jump to position after this occurence,so that we do not iterate and check for positon of duplicate ,this can be done by storing the last occurences of the characters in the map

int optimal(string &s)
{
    int left = 0, right = 0, length = 0;
    int n = s.length();
    unordered_map<char, int> map;
    while (right < n)
    {
        // when we find the duplicate,we are directly moving left pointer to position last occurence +1 ,so that the duplicate is not included in the curent substring
        if (map.find(s[right]) != map.end())
        {
            // we will also encounter the situation where we already excluded the character ,so we take maximum of the present left and map[s[right]]+1
            // example geeksforgeeks
            left = max(map[s[right]] + 1, left);
        }
        // mapping current character with its position
        map[s[right]] = right;
        length = max(right - left + 1, length);
        cout << s[left] << " " << s[right] << " " << length << endl;
        right++;
    }
    return length;
} 
int main()

{
    string s;
    cin >> s;
    cout << optimal(s) << endl;
    return 0;
}