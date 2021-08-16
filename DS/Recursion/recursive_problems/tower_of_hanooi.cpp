// problem statement
// print the moves to be done inorder to shift discs from tower 1 to tower 3, by following the constraints of tower of hanoi /
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void toh(int n, int a, int b, int c)
{
    if (n <= 0)
        return;
    toh(n - 1, a, c, b);
    // move n-1 disc form a to b using c
    cout << "[" << a << "," << c << "]" << endl;
    // move a disc from a to c
    toh(n - 1, b, a, c);
    // move n-1 disc from b to c using a
}


int main()

{
    int n;
    cin >> n;
    toh(n, 1, 2, 3);

    return 0;
} 