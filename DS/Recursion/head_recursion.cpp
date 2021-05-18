// in this we will look at the head recursion 
// in head recursion the recursive call is the first statement of the function 

// so every thing does the funtion does is performed in the returning time only 
#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
// printing the numbers which are less than or equal to the given number in ascending order 

// head recursion cannot be converted into the loop type ,if we want to convert we want to make some modification 

// so we cannot determine which is better among the head recursion and the loop 
void head_recursion(int n)
{
    if(n > 0)
    {
        head_recursion(n - 1);
        cout<< n <<endl;
    }
}
int main() 

{
    int n;
    cin >> n;
    head_recursion(n);

    return 0; 

}