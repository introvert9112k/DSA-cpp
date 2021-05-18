// problem statement ---------
// convert the decimal to binary using recursion 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
string decimal_to_binary(int n)
{
    return n == 0 ? "" : decimal_to_binary(n / 2) + to_string(n % 2);
}
int main() 

{
    int n;
    cin >> n; 
    cout<< "the binary representation of number is : "<< decimal_to_binary(n) << endl;
    
    return 0;
 
}  