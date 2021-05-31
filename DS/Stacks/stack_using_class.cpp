// in this we will implement the stack using the class
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
class stack
{
private:
    int size;
    int top;
    int *arr;

public:
    stack(int value)
    {
        size = value;
        top = -1;
        arr = new int[size];
    }
    void push(int value); //member function declaration
    bool isempty();
    bool full();
    int pop();
    int peek(int position);
    int top_element();
};
// this is how we define the member function outside the class

// syntax is "return-type class :: function_name", class:: is known as the membership label and "::" is known as the scope resolution operator

// class :: function states that the function is belong to that particular class

// return-type class :: function means that the function is belong to the provided class and return type is the provided one
bool stack::full()
{
    return top == size - 1 ? true : false;
}
bool stack::isempty()
{
    return top == -1 ? true : false;
}
void stack::push(int value)
{
    if (full())
        cout << "stack overflown" << endl;
    else
    {
        top++;
        arr[top] = value;
    }
} 
int stack::pop()
{
    int x = -1;
    if(isempty())
        cout << "stack underflown" << endl;
    else
    {
        x = arr[top];
        top--;
   }
   return x;
}
int stack::top_element() 
{
    int x = -1;
    if(isempty())
        cout << "stack underflown" << endl;
    else
        x = arr[top];
    return x;
}
int stack::peek(int position)
{
    int x = -1;
    if(isempty())
        cout << "stack underflown" << endl;
    else
    {
        int index = top - position + 1;
        x = arr[index];
    }
    return x;
} 
int main()

{
    int size;
    cout << "enter the size of the stack : " << endl;
    cin >> size;
    stack st(size);
    st.push(1);
    st.push(2);
    st.push(3);
    cout << "the top element of the stack is : " << st.top_element() << endl;
    cout << "the popped value is : " << st.pop() << endl;
    cout << "the element at second position is : " << st.peek(2) << endl;
    return 0;
} 