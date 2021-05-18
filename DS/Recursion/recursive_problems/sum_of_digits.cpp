// problem statement 
// find the sum of the digits of the number using recursion 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int sum_of_digits(int n)
{
    if(n>0)
       return n%10 + sum_of_digits(n/10); 
    return 0;
} 
int main() 

{
    int n;
    cin >> n;
    cout<< "the sum of the digits is : " << sum_of_digits(n) << endl; 

    return 0;

}  