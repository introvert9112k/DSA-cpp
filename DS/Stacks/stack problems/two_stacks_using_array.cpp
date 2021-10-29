#include <bits/stdc++.h>
using namespace std;

class Twostack
{
    int *arr;
    int top1;
    int top2;
    int size1;
    int size2;
    int maxsize;

public:
    Twostack(int size = 10)
    {
        top1 = -1;
        top2 = size;
        size1 = 0;
        size2 = 0;
        maxsize = size;
        arr = new int[maxsize];
    }
    bool full()
    {
        return top1 + 1 == top2;
    }
    bool empty1()
    {
        return top1 == -1;
    }
    bool empty2()
    {
        return top2 == maxsize;
    }
    int getsize1()
    {
        return size1;
    }
    int getsize2()
    {
        return size2;
    }
    int gettop1()
    {
        return top1 == -1 ? -1 : arr[top1];
    }
    int gettop2()
    {
        return top2 == maxsize ? -1 : arr[top2];
    }
    void push1(int x)
    {
        if (full())
        {
            cout << "stack overflown" << endl;
            return;
        }
        else
        {
            arr[++top1] = x;
            size1++;
        }
    }
    void push2(int x)
    {
        if (full())
        {
            cout << "stack overflown" << endl;
            return;
        }
        else
        {
            arr[--top2] = x;
            size2++;
        }
    }
    void pop1()
    {
        if (empty1())
        {
            cout << "stack underflown" << endl;
            return;
        }
        else
        {
            arr[top1--] = -1;
            size1--;
        }
    }
    void pop2()
    {
        if (empty2())
        {
            cout << "Stack underflown" << endl;
            return;
        }
        else
        {
            arr[top2++] = -1;
            size2--;
        }
    }
};
int main()
{
    Twostack ts(10);
    ts.push1(10);
    ts.push1(20);
    ts.push2(30);
    ts.push2(40);
    cout << ts.gettop1() << endl;
    cout << ts.gettop2() << endl;
    cout << "stack 1 size : " << ts.getsize1() << " stack 2 size  " << ts.getsize2() << endl;
    ts.pop1();
    ts.pop1();
    ts.pop1();

    return 0;
}
