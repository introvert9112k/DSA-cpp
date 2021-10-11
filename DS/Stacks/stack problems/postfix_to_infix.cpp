// problem statement
// given an postfix expression we should calculate the value of the infix expression

#include<bits/stdc++.h>
using namespace std;

int infixvalue(string &postfix)
{
    stack<int> stack;
    int k,res=0;
    for (int i = 0; i < postfix.length(); i++)
    {
        k = int(postfix[i]) - 48;
        if (k >= 0 and k <= 9)
            stack.push(k);
        else 
        {
            int second = stack.top();
            stack.pop();
            int first = stack.top();
            stack.pop();
            if(postfix[i] == '*')
                res = first * second;
            else if(postfix[i] == '-')
                res = first - second;
            else if(postfix[i] == '/')
                res = first / second;
            else
                res = first + second;
            // cout << res << endl;
            stack.push(res);
        }
    }
    return res;
} 

int main() 

{
    string postfix;
    cin >> postfix;
    cout << infixvalue(postfix) << endl;

    return 0;

}