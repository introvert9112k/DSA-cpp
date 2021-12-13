#include<bits/stdc++.h>
using namespace std;
struct colors
{
    bool red = false, blue = false, green = false;
};
class Solution
{
public:
    int countPoints(string rings)
    {
        int n = rings.length();
        struct colors arr[10];
        for (int i = 0; i < 2 * n; i += 2)
        {
            int rod = rings[i + 1] - '0';
            if (rings[i] == 'R')
                arr[rod].red = true;
            else if (rings[i] == 'G')
                arr[rod].green = true;
            else
                arr[rod].blue = true;
        }
        int cnt = 0;
        for (int i = 0; i < 10; i++)
            if (arr[i].red and arr[i].green and arr[i].blue)
                cnt++;
        return cnt;
    }
};
int main()

{
    Solution sai;
    string rings = "B0B6G0R6R0R6G9";
    cout << sai.countPoints(rings) << endl;

    return 0;
} 