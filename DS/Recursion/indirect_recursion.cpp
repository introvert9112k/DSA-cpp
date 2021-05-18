// in this we will look at the indirect recursion 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void funA(int n);

void funB(int n)
{
    if(n >0)
    {
        cout<< n <<endl;
        funA(n - 1);
    } 
}
void funA(int n)
{
    if(n>0)
    {
        cout<< n <<endl;
        funB(n - 1);
    }
}
int main() 

{
    int n;
    cin >> n;
    funA(n);

    return 0;

} 