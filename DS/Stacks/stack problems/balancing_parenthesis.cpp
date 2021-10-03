#include <iostream>
#include <string>
#include <algorithm>
#include <stack>
// problem statement
// given a string containing ( ,) {, } and [,] we should find whehter the string is balanced or not

using namespace std;
bool balance_parenthesis(string &sai)
{
    stack<char> stack;
    int length = sai.length();
    for (int i = 0; i < length; i++)
    {
        if (sai[i] == '(' or sai[i] == '{' or sai[i] == '[')
            stack.push(sai[i]);
        else if (sai[i] == ')')
        {
            if (stack.empty() or stack.top() != '(')
                return false;
            else
                stack.pop();
        }
        else if (sai[i] == '}')
        {
            if (stack.empty() or stack.top() != '{')
                return false;
            else
                stack.pop();
        }
        else if (sai[i] == ']')
        {
            if (stack.empty() or stack.top() != '[')
                return false;
            else
                stack.pop();
        }
    }
    return stack.empty();
} 
int main()

{
    string sai;
    cin >> sai;
    if(balance_parenthesis(sai))
        cout << "balanced" << endl;
    else
        cout << "unbalanced" << endl;
    return 0;
}
