#include <bits/stdc++.h>
using namespace std;
// Prefix expression is similar to the Postfix exression evaluation,The only thing is we traverse from right to left in Prefix evaluation instead of left to right
void EvaluatePostfix(vector<string> characters)
{ 
    stack<int> st;
    for (int i = characters.size() - 1; i >= 0; i--)
    {
        string st = characters[i];
        if (str == "+" || str == "-" || str == "*" || str == "/")
        {
            int second = st.top();
            st.pop();
            int first = st.top();
            st.pop();
            if (str == "+")
                st.push(first + second);
            else if (str == "*")
                st.push(first * second);
            else if (str == "-")
                st.push(first - second);
            else
                st.push(first / second);
        }
        else
            st.push(stoi(str));
    }
    cout << st.top() << endl;
} 
int main()

{

    return 0;
} 