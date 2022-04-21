#include <bits/stdc++.h>
using namespace std;

/* Infix to prefix is same as the Infix to postfix conversion with Little changes.
1.Iterate from right to left
2.After completion reverse the prefix.This would be our answer.
*/

string infixToprefix(string s)
{
    // Your code here
    stack<char> st;
    unordered_map<char, int> priority = {{'+', 1}, {'-', 1}, {'*', 2}, {'/', 2}, {'^', 3}};
    string prefix;
    for (int i = s.size() - 1; i >= 0; i--)
    {
        if (s[i] == ')')
            st.push(')');
        else if (s[i] == '(')
        {
            while (!st.empty() && st.top() != ')')
            {
                prefix.push_back(st.top());
                st.pop();
            }
            st.pop();
        }
        else if (priority.find(s[i]) == priority.end())
            prefix.push_back(s[i]);
        else
        {
            if (st.empty())
                st.push(s[i]);
            else
            {
                /*Notice the equality here, Here we are moving from right to left, if we found the operator with same priority that mean In actual the current operator
                is left to the stack's top operator which has high priority so push into stack*/
                if (st.top() == ')' || priority[s[i]] >= priority[st.top()])
                    st.push(s[i]);
                else
                {
                    /*Notice only > here ,We are popping the operators the moment when we get stack.top() priority is same as the current operator priority.
                    That mean stack.top() is right of the current operator. Which mean current operator has high priority than stack's top operator,so don't pop it.*/
                    while (!st.empty() && st.top() != ')' && priority[st.top()] > priority[s[i]])
                    {
                        prefix.push_back(st.top());
                        st.pop();
                    }
                    st.push(s[i]);
                }
            }
        }
    }
    while (!st.empty())
    {
        prefix.push_back(st.top());
        st.pop();
    }
    reverse(prefix.begin(), prefix.end());
    return prefix;
} 
int main()
{
    string infix = "x+y/z-w*u";
    cout << infixToprefix(infix) << endl;
    return 0;
} 