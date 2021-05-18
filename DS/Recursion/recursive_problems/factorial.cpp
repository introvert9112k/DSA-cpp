// in this we will look at the factorial of number 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
int factorial(int n)
{
    return n==0 ? 1 :n * factorial(n - 1);
}
int main() 

{
    int n;
    cin >> n;
    cout<< "the factorial of number is : " << factorial(n);

    return 0;

} 