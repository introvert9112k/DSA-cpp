// problem statement
// find the gcd of two numbers using recursion
#include <iostream>
#include <string>
#include <algorithm>
// while
//     calculating the gcd we should keep in mimd two things
//     1.gcd(a,b) == gcd(b,a%b)
//     2.gcd(a,0) is a
// first axiom is the recursive relation
// secind axiom is the base condition

using namespace std;
int i = 1;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
} 
int main()

{
    int a, b;
    cin >> a;
    cin >> b;
    cout << gcd(a, b) << endl;

    return 0;
}