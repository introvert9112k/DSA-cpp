#include <bits/stdc++.h>
using namespace std;
// /Given a array of strings with the operators +,-*,/ and the numbers of the postfix expression.Evaluate it and find the result.
void EvaluatePostfix(vector<string> characters)
{
    stack<int> st;
    for (auto &str : characters)
    {
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