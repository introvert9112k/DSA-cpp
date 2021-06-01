// stack is last in first output 
// LIFO
// whatever is the last element popped first

// ------------stack functions------------
// size()
// = 
// top()
// empty()
// push() pop()

#include<iostream>
#include<string>
#include<algorithm>
#include<stack>

using namespace std;
int main() 

{
    stack<int> sai;
    // we cannot directly intialize the elements to stack,we should push it one by one
    for (int i = 0; i < 10; i++)
        sai.push(i);
    // let us pop some elements out of stack
    // ----pop----------
    sai.pop();
    // let us copy into another stack
    stack<int> sri;
    sri = sai;

    // ---size function-------
    cout<< "the size of the stack is : " << sai.size() <<endl;

    // ----top---------/
    // top will return the top element of the stack 
    cout<< "the top element of the stack is : " << sai.top() <<endl;
   
    // stack hides its elements,we cannnot access the elements using  iterators,indexing 
    // we cannot acess the other elements of the stack except the first element ,inorder to print the all the elements of the stack we should pop out the elements one by one until the stack is empty 
    
    // let us print the elements of stack
    cout<< "the elements of the stack are : " <<endl; 
    while (!sai.empty())
    {
        cout<< sai.top() <<endl;
        sai.pop();
    } 
    
    if(sai.empty()) 
    cout<< "the stack is empty now" <<endl;
    else 
    cout<< "the stack is not empty" <<endl; 

    return 0;

}