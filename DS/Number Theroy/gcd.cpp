#include<bits/stdc++.h>
using namespace std;
// given two numbers find the gcd of the numbers
// gcd of a,b is same as the gcd of teh b,a%b

// Euclids Algorthims for finding the gcd
int gcd(int a, int b)
{
    if(b==0)
        return a;
    return gcd(b, a % b);
} 
// gcd of the three numbers a,b,c is gcd(gcd(a,b),c)
// this can be used to calculate the gcd of the array of numbers
int arraygcd(vector<int> &v)
{
    int x;
    x = gcd(v[0], v[1]);
    for (int i = 2; i < v.size(); i++)
        x = gcd(x, v[i]);
    return x;
} 

int main() 

{
    int a, b;
    cin >> a >> b;
    cout << "gcd of the " << a << " and " << b << " is " << gcd(a, b) << endl;
    // there is also built in function to find the gcd i.e __gcd
    cout << "gcd of the numbers  is :  "<<__gcd(a, b) << endl;
    // LCM
    // there is a realation between the gcd and lcm, product of numbers divided by the gcd gives the lcm
    // product/gcd = lcm
    cout << "the lcm of the two numbers is : " << (a * b) / gcd(a, b) << endl;
    // Gcd of the array of numbers
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++)
        cin >> v[i];
    cout<<"gcd of the array of elements is : " <<arraygcd(v)<<endl;

    // Minimum fraction
    // given a fraction in p/q form,we should convert int the smallest fraction form, that mean p/q should become coprimes
    // this can acheived by dividing the numerator and denominator by their gcd
    
    return 0;

}  