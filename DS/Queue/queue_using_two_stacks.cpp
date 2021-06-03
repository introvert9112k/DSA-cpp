// in this we will implement the queue using the two stacks

// how it is attaied :
// take the two stacks let be s1 and s2
// push the elements into the s1
// when popping copy the elements of s1 into s2 for the first pop,for the further pops check whether the s2 is empty or not if s2 is not empty then pop the top element from the stack 2 and if it is empty then again copy the elements from stack 1 into stack2 .
// whenever the both the stacks become empty return -1

// let us implement using the built stl stacks
#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
stack<int> s1; // for pushing the elements
stack<int> s2; //for popping the elements
// let us define these two stacks globally so that every function can acess them
void enqueue(int value)
{
    s1.push(value);
}
int dequeue()
{

    if (s2.empty()) //checking whether the stack 2 is empty or not,if it is empty copy elements from stack 1
    {
        if (s1.empty()) //checking stack 1 is empty or not ,if it is empty then there are no elements in queue
            return -1;

        else
        {
            //   this mean the s2 is empty and s1 is not empty so copying the s1 elements to s2
            while (!s1.empty())
            {
                s2.push(s1.top());
                s1.pop();
            }
        }
    } 
    int x = s2.top();
    s2.pop();
    return x;
} 
int main()

{
    enqueue(3);
    enqueue(4);
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    cout << dequeue() << endl;
    return 0; 
} 