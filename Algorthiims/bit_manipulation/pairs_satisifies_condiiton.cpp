// given the two conditions
// x + y = S
// x^y = X
// For given a and b we should find the x and y such that the above equations hold . if not exist return -1
#include <bits/stdc++.h>
using namespace std;

// -----------One Important formula---------------
//  For given two numbers x and y the equation always holds.  -- x + y = x^y + 2*(x&y) ---
// from given equations the _Identity turns out to be  (S - X)/2 =  x&y
// we know the xor of x and y and bitwise and of x and y from them we can find the a and b

// Once we find A, we can find all bits of ‘a’ and ‘b’ using below rules.

// If X[i] = 0 and A[i] = 0, then a[i] = b[i] = 0. Only one possibility for this bit.
// If X[i] = 0 and A[i] = 1, then a[i] = b[i] = 1. Only one possibility for this bit.
// If X[i] = 1 and A[i] = 0, then (a[i] = 1 and b[i] = 0) or (a[i] = 0 and b[i] = 1), we can pick any of the two.
// If X[i] = 1 and A[i] = 1, result not possible (Note X[i] = 1 means different bits)
 
void findxy(int S, int X)
{
    int a = 0, b = 0;
    int A = (S - X) / 2;
    // finding all the bits of a and b
    for (int i = 0; i < 32; i++)
    {
        int Ai = A & (1 << i);
        int Xi = X & (1 << i);
        if (Xi == 0 and Ai == 0)
            //  here ai = 0 and bi = 0 so do nothing
            continue;
        else if (Xi == 0 && Ai > 0)
            a = a | (1 << i), b = b | (1 << i); // making the ith bit of a and b to set

        else if (Xi > 0 && Ai == 0)
            a = a | (1 << i); // making ith bit of a to be set
        else
        {
            cout << "No such combiantion of x and y are possible" << endl;
            return;
        }
    }
    cout << a << " " << b << endl;
}
int main()
{
    int S, X;
    cin >> S >> X;
    findxy(S, X);
    return 0;
}  