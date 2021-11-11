// problem statement
// Add two numbers without + operator
#include <bits/stdc++.h>
using namespace std;

int add(int a, int b)
{
    int sum = 0, carry = 0;
    while (b != 0)
    {
        sum = a ^ b;
        carry = a & b;
        a = sum;
        b = carry << 1;
    }
    return sum;
}
int subtract(int a, int b)
{
    int res = 0, borrow = 0;
    while (b != 0)
    {
        res = a ^ b;
        borrow = ~a & b;
        a = res;
        b = borrow << 1;
    }
    return res;
}
int main()

{
    int a, b;
    cin >> a >> b;
    cout << add(a, b) << endl;
    cout << subtract(a, b) << endl;
    return 0;
} 

// https://www.youtube.com/watch?v=Nojk2IRmfVM&t=2789s&ab_channel=CodeChef 