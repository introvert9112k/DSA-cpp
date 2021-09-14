// problem statement
// given two numbers x and y,we should say whether y is power of x or not
// Approach
// if floor(log(y)/log(x)) == ceil(log(y)/log(x)) then the y is power of x
// this conditon fails when x ==1 as log1 = 0, division by zero is not feasible
// so if x ==1 and then check if y == 1 if this is true return true, and if x==1 and y!=1 then return false
// any number cannnot be power of 1 except the 1 iteself
#include <bits/stdc++.h>
using namespace std;
int checkpower(int y, int x)
{
    if (x == 1 and y == 1)
        return 1;
    else if (x == 1 and y != 1)
        return 0;
    return floor(log(y) / log(x)) == ceil(log(y) / log(x)) ? 1 : 0;
}
int main()

{
    int y, x;
    cin >> y >> x;
    cout << checkpower(y, x) << endl;
    // we can also find the nearest power of number x which is nearer to y
    cout << "nearest power of " << x << " which is nearer to " << y << " is " << endl;
    cout << floor(log(y) / log(x)) << endl;
    return 0;
}  