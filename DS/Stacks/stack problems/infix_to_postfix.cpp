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
int checking(char x)
{
    if (x == '+' or x == '-')
        return 1;
    else if (x == '*' or x == '/')
        return 2;
    else if (x == '^')
        return 3;
    else if (x == '(')
        return 4;
    else if (x == ')')
        return 5;
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
        if (checking(s[i]))
        {
            if (stack.empty())
                stack.push(s[i]);
            else if (s[i] == ')')
            {
                while (!stack.empty() and stack.top() != '(')
                {
                    postfix.push_back(stack.top());
                    stack.pop();
                }
                stack.pop();
            }
            else if (checking(s[i]) == 3 or (checking(s[i]) > checking(stack.top())))
                stack.push(s[i]);
            else
            {
                while (!stack.empty() and stack.top()!='(' and checking(s[i]) <= checking(stack.top()))
                {
                    postfix.push_back(stack.top());
                    stack.pop();
                }
                stack.push(s[i]);
            }
        } 
        else
        {
            postfix.push_back(s[i]);
        }
    }
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