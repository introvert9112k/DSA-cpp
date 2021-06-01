#include <iostream>
#include <string>
#include <algorithm>
#include <stack>

using namespace std;
void balance_parenthesis(string &sai)
{
    stack<char> s;
    int length = sai.length();
    for (int i = 0; i < length; i++)
    {
        if (sai[i] == '(')
            s.push('(');
        else if (sai[i] == ')')
        {
            if (s.empty())
            {
                cout << "not balanced" << endl;
                return;
            }
            s.pop();
        }
    }
    if (s.empty())
        cout << "balanced" << endl;
    else
        cout << "not balanced" << endl;
} 
int main()

{
    string sai;
    cin >> sai;
    balance_parenthesis(sai);
    return 0;
}

