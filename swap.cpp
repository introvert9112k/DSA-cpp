// in this we will look at how to swap the two numbers in various ways 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void using_temp(int &a ,int &b)
{
    int temp;
    temp = a;
    a = b;
    b = temp;
}
void using_xor(int &a, int &b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;
}
void using_arthematic(int &a , int &b)
{
    a = a + b;
    b = a - b;
    a = a - b;
}
int main() 

{

    int a, b;
    cin >> a;
    cin >> b;
    using_temp(a, b);
    cout<< "the a and b after function using_temp are : " << a << " " << b <<endl;
    using_xor(a, b);
    cout << "the a and b after function using_xor is : " << a << " " <<b << endl;
    using_arthematic(a, b);
    cout<< "the a and b after function using_arthematic is : " << a << " " << b <<endl;
    return 0;

}