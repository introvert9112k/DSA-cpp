// in this we will look at the fibonanci series
// the series 1 1 2 3 5 8 etc is known as the fiboonanci series
// in fiboanci series every number is sum of the previous two numbers
// let us find the nth term of the fibonanci series using recursion and through conventional method
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
long long int fibonanci_series(long long int n)
{
    long long int temp1 = 1, temp2 = 1, sum;
    for (long long int i = 0; i < n - 2; i++)
    {
        sum = temp1 + temp2;
        temp2 = sum;
        long long int temp = temp1;
        temp1 = temp2;
        temp2 = temp;
    } 
    return sum;
}
long long int recursive_fibonanci(long long int n)
{
    if (n == 1 or n == 2)
        return 1;
    return recursive_fibonanci(n - 1) + recursive_fibonanci(n - 2);
}
int main()

{
    int n;
    cin >> n;
    cout << fibonanci_series(n) << endl;
    // cout<< recursive_fibonanci(n) <<endl; 

    return 0;
}
