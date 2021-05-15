// in this we will look at the algorthim to find whether the given number is prime or not
#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

string way1(int a)
{
    if (a == 1 || a == 0)
        return "not prime";
    else if (a == 2)
        return "prime";
    for (int i = 2; i < a; i++)   //it's complexity is O(N)
    {
        if (a % i == 0)
            return "not prime";
    }
    return "prime";
}

string way2(int a)
{
    if (a == 0 || a == 1)
        return "not prime";
    else if (a == 2)
        return "prime";

    for (int i = 2; i <= a / 2; i++)
    {
        if (a % i == 0)
            return "not prime";     //it's complexity is O(N/2)
    }
    return "prime";
} 

string optimised_way(int a)
{
    if(a == 0 || a == 1)
     return "not prime";
    else if (a == 2)
      return "prime";
    for(int i= 2; i<= sqrt(a); i++)
    {
        if(a%i == 0)
         return "not prime";     //it's complexity is O(sqrt(N))
    }   
    return "prime";
} 
int main()

{
    int a;
    cin >> a;
    string result = optimised_way(a);
    cout<< result <<endl; 
    return 0;
} 