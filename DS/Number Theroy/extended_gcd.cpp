// given an equation ax + by = gcd(a,b)
// we have to find the x and y such that it satisfies the equation
// this can be done with the extended gcd
#include <bits/stdc++.h>
using namespace std;
struct triplet
{
    int x, y, gcd;
};
triplet extendedgcd(int a, int b)
{
    if (b == 0)
    {
        triplet ans;
        ans.x = 1;
        ans.y = 0;
        ans.gcd = a;
        return ans;
    }
    triplet temp = extendedgcd(b, a % b);
    triplet final_ans;
    final_ans.x = temp.y;
    final_ans.y = temp.x - (a / b) * temp.y;
    final_ans.gcd = temp.gcd;
    return final_ans;
} 
int main()

{
    int a, b;
    cin >> a >> b;
     triplet ans = extendedgcd(a, b);
    cout << "x-->  " << ans.x << " "
         << "y--->  " << ans.y << " "
         << "gcd--->  " << ans.gcd << endl;
    return 0;
} 