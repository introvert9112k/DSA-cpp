

// bool PowerofTwo(int n)
// {
//     if (n <= 0) // 0 and negative numbers cannot be power of two
//         return false;
//     while (n % 2 == 0) // iterate until n is divisible by 2
//         n = (n >> 1);  // dividing n by 2, we can also n = n/2,but bitwise operators are faster than arthematic operators
//     return (n == 1);   // if n is reduced to 1,then it is power of 2
// }
// bool PowerofTwo2(int n)
// {
//     if (n <= 0) // n<=0 return false
//         return false;
//     if (n == 1) // n == 1 return true
//         return true;
//     return n % 2 == 0 && PowerofTwo2(n >> 1); // if n is divisible by 2,then recursive call is called upon n/2 if not returns false
// }

// bool PowerofTwo(int n)
// {
//     if (n <= 0)
//         return false;
//     int setbitscnt = 0; // to store the no of setbits in n.
//     while (n > 0)
//     {
//         if (n & 1)
//             setbitscnt++;
//         n = n >> 1;
//     }
//     return setbitscnt == 1; // if no of setbits is 1 then it is power of 2
// }
#include <bits/stdc++.h>
using namespace std;

// bool PowerofTwo(int n)
// {
//     if (n <= 0)
//         return false;
//     int setbitscnt = 0;
//     while (n > 0)
//     {
//         n = n - (n & -n); // turning off right most set bit
//         setbitscnt++;     // updating the setbits count
//     }
//     return setbitscnt == 1;
// }

// bool PowerofTwo(int n)
// {
//     if (n <= 0)
//         return false;
//     return floor(log2(n)) == ceil(log2(n));
// } 

// bool PowerofTwo(int n)
// {
//     if(n<=0)
//         return false;
//     return __builtin_popcount(n) == 1;
// }

bool PowerofTwo(int n)
{
    if(n<=0)
        return false;
    return (n & (n - 1)) == 0;
} 
int main()

{
    int n = 8;
    if (PowerofTwo(n))
        cout << n << " is power of 2" << endl;
    else
        cout << n << " is not power of 2" << endl;
    return 0;
} 
