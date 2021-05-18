// in this we wil look at the example of the tree recursion 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void tree_recursion(int n)
{
    if(n > 0)
    {
        cout<< n <<endl;
        tree_recursion(n - 1);
        tree_recursion(n - 1);
    }
}
// notice that the here there are two recursive calls inside the function hence it is example of the tree recursion 

// space complexity is equal to the no of activation records created 
// time complexity is equal to the no  of function calls that occured during the execution of the recursio function /

int main() 

{
    int n;
    cin >> n;
    tree_recursion(n);

    return 0;

}