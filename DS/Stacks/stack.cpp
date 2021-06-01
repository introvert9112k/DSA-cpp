// in this we will implement stack using the aray
#include <iostream>
#include <string>
#include <algorithm>

using namespace std;
struct stack
{
    int size;
    int top;
    int *arr;
};

bool isempty(struct stack *st)
{
    return st->top == -1 ? true : false;
}

bool full(struct stack *st)
{
    return st->top == st->size - 1 ? true : false;
}

void push(struct stack *st, int value)
{
    if (full(st))
        cout << "stack overflown" << endl;
    else
    {

        st->top++;
        st->arr[st->top] = value;
    }
}

int pop(struct stack *st)
{
    int x = -1;
    if (isempty(st))
        cout << "stack is underflown" << endl;
    else
    {
        x = st->arr[st->top];
        st->top--;
    }
    return x;
}

int top(struct stack *st)
{
    int x = -1;
    if (isempty(st))
        cout << "stack underflown" << endl;
    else
        x = st->arr[st->top];
    return x;
}

int peek(struct stack *st, int position)
{
    int x = -1;
    if (st->top - position + 1 > 0)
    {
        int index = st->top - position + 1;
        x = st->arr[index];
    } 
    return x;
} 
int main()

{
    struct stack st;
    cout << "enter the size of the stack: " << endl;
    cin >> st.size;
    st.arr = new int[st.size];
    st.top = -1;

    push(&st, 1);
    push(&st, 2);
    push(&st, 3);
    cout << "the element at first position is : " << peek(&st, 1) << endl;
    cout << "popped item is : " << pop(&st) << endl;
    cout << "the top value in stack is : " << top(&st) << endl;
    return 0;
}  