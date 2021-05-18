// problem statement 
// find the sum of the natural numbers which are less than or equal to the given number 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int sum_of_natural_numbers(int n)
{
    return n == 0 ? 0 : n + sum_of_natural_numbers(n - 1);
}
int main() 

{
    int n;
    cin >> n;
   int result= sum_of_natural_numbers(n);
    cout<< "sum of natural numbers upto n is : " <<result <<endl;
    return 0;

} 