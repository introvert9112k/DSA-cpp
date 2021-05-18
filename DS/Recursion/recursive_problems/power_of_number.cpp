// problem statement ----------
// calculate the power of a number using recursion 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
long long exponentation(int base ,int power)
{
   
        return power > 0 ? base * exponentation(base,power - 1) : 1;
    
} 
// recursion repeats for the n+1 calls 
// so the time complexity of the recursive exponentiation is O(N) 

// best way to calculate the exponentiation 
// using the bits 

long long bit_exponentation(long long base,int power) 
{
    long long result = 1;
    while(power > 0)
    {
        if(power&1)
            result = result * base;
        base = base * base;
        power = power >> 1;

    }
    return result;
} 
// every number has atmost logN bits 
// so the complexity of the bit_exponentation is O(logN) which is better than the recursive exponentation 

int main() 

{
    int base, power;
    cin >> base;
    cin >> power;
    cout<<exponentation(base, power)<<endl; 
    cout<< bit_exponentation(base,power) <<endl; 
    return 0;

} 