// in this we will look at the tail recursion ,and compare it with the loop and determine which is the best among the tail recursion and loops 

#include<iostream>
#include<string>
#include<algorithm>

using namespace std;
void tail_recursion(int n)
{
    if(n > 0)
    {
        cout<< n <<endl;
        tail_recursion(n - 1);
    }
}
// notice that in the above recursive function there are no statments after the recursive call so it is example of tail recursion 
// in the forwarding phase it prints the n 
// and in the returning phase it does nothing 
// the same can be achieved using the loop 

void loop(int n)
{
    while(n > 0)
    {
        cout<< n <<endl;
        n--;
    }
} 

// -----------------comparing the tail recursion and loop---------
// let us compare both using the time and space complexity 

// time complexity of the tail recursion is O(N) and space complexity is O(N) because the n+1 activation records are created in the stack so it has linear space complexity 

// time complexity of loop is O(N) and space complexity is O(1) 

// So it is optimal way to use the loop instead of recursion as loop takes constant space complexity and tail reccursion takes linear complexity 

int main() 

{
        //  let us print the postive numbers that are less than or equal to provided integer
        int n;
        cin >> n;
        cout << "using tail recursion: " << endl;
        tail_recursion(n);
        cout<< "using the loop : " <<endl;
        loop(n); 
        return 0;

} 