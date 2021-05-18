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
// second axiom is the base condition

// lcm of two numbers can be calculated if the gcd is known 

// formula to calculate lcm is : 
//  lcm*gcd  = a*b
//  that mean the product of lcm and gcd of two numbers is equal to the product of two numbers 
// 
//  so if we know the gcd then using the formula we can find the lcm 
using namespace std;
int i = 1;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
} 
int lcm(int a,int b)
{
    int g = gcd(a, b);
   return (a * b) / g;
}
int main()

{
    int a, b;
    cin >> a;
    cin >> b;
    cout << "gcd of the numbers is : " << gcd(a, b) << endl;
    cout<< "the lcm of the numbers is : "<<lcm(a,b) <<endl; 

    return 0;
}