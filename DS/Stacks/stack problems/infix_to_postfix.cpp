#include <bits/stdc++.h>
#define int long long
#define mp make_pair
#define mod 1000000007
#define ps(x, y) fixed << setprecision(y) << x
#define pb push_back
#define ppb pop_back
#define vi vector<int>
#define vii vector<pair<int, int>>
#define si stack<int>
#define li list<int>
#define endl "\n"
#define pi pair<int, int>
#define scan(h) scanf("%lld", &h)
#define st(g, h) scanf("%lld %lld", &g, &h)
#define print(g) printf("%lld", g)
#define deb(x) cout << #x << " = " << x << endl;
#define fo(i, n) for (int i = 0; i < n; i++)
#define fok(i, k, n) for (int i = k; i >= n; i--)

using namespace std;

bool cmp(int a, int b)
{
    return a > b;
}
int power(int a, int b)
{
    int result = 1;
    while (b > 0)
    {
        if (b & 1)
            result = result * a;
        a = a * a;
        b = b >> 1;
    }
    return result;
}
// there are main 5 steps to be followed while converting the infix expresssion to postfix

// order of precedence is ^  >  * /  > + -
// ^ has highest precendence and * / has equal precedence + - has also equal precendence

// steps to be followed:

// Traverse the infix expression

//   (  --------- push into stack

//   operand ------------ print it or store it

//   )  ----------- keep poping from the stack until the (  is found

//   operator(+,-,*,/,^) ---if stack is empty push it
//                          else
//                             compare the top operand in the stack
//                          if higher precedence then push it
//                          else
//                             keep popping from the stack until the lowe precedence is found
// pop until the stack is empty and print it

// brackets has higher prcedence than any other operators, +,- and * / has associtivity of left to right that mean the among +,- or *,/ the first occured one has higher precedence.
// ^ associtivity is from right to left that mean second occurence of ^ has higher precedence.
// ^ has higher precedence than +,-,*,/ and higher precedence than first occurence so whenever we encounter the ^ we push it into the stack
// brackets has higher precedence than any other operator

int checking(char x)
{
    // assinging the priority values
    if (x == '+' or x == '-')
        return 1;
    else if (x == '*' or x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else if (x == '(' or x == ')')
        return 4;
    // for operand
    else
        return 0;
}
string infixToPostfix(string s)
{
    // Your code here
    stack<char> stack;
    string postfix;
    for (int i = 0; i < s.length(); i++)
    {
        // checking whether the character is operand or not,if not proceed else we should print or store it
        if (checking(s[i]))
        {
            // if character is "(" then push into stack
            if (s[i] == '(')
                stack.push(s[i]);
            else if (s[i] == ')')
            {
                // pop until we found the closing bracket,in postfix expresiion there would be only operators and operands no brackets
                while (!stack.empty() and stack.top() != '(')
                {
                    postfix.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else
            {
                // if stack is empty push into stack
                if (stack.empty())
                    stack.push(s[i]);
                else
                {
                    // ^ has right to left associativity it has precedence any other operator but not than "(" so if the top element is not opening bracket then push ^ into stack
                    if (s[i] == '^' and stack.top() != '(')
                        stack.push('^');
                    // if the current operator has higher precedence than the operator at top then push into stack
                    else if (checking(s[i]) > checking(stack.top()))
                        stack.push(s[i]);
                    // if current operator has less precedence than the top operator ,pop the stack until the less precedence operator is found and after that push the current operator into stack
                    // if we found '(' opening bracket in middle stop there itself,because "(" should be removed from the stack whenever the ")" closing bracket is encountered
                    else
                    {
                        while (!stack.empty() and stack.top() != '(' and checking(stack.top()) >= checking(s[i]))
                        {
                            postfix.push_back(stack.top());
                            stack.pop();
                        }
                        stack.push(s[i]);
                    }
                }
            }
        }
        // storing operanding in the postfix string
        else
        {
            postfix.push_back(s[i]);
        }
    }
    // storing the remaining elements in stack into the postfix string
    while (!stack.empty())
    {
        postfix.push_back(stack.top());
        stack.pop();
    }
    return postfix;
}
int32_t main()
{
    string infix;
    cin >> infix;
    cout << infixToPostfix(infix) << endl;
    return 0;
}
