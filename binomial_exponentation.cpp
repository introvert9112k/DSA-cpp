// in this we will find the fastest way of calculating the exponentiation
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
void brute_force(int a, int b)
{
    long long int result = 1;
    for (int i = 1; i <= b; i++)
        result = result * a;
    cout << result << endl;
}

void binomial_exponentation(long long int a, long long b)
{
    long long int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    } 
    cout << result << endl; //time complexity is O(logN) because the any number has atmost logN binomial digits 
    //this can calculate the exponentaion value that is under the range of long long int
} 

void modular_exponentation(long long a, long long b,long long m) 
{
  long long int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = (result * a)%m;
        a = (a * a)%m; 
        b = b >> 1;
    } 
    cout << result;
} 

int main() 

{
    int a, b;
    cin >> a;
    cin >> b;
    long long m;
    cin>>m;
    // brute_force(a, b);
    // binomial_exponentation(a, b);
    modular_exponentation(a,b,m);

    return 0;
} 
