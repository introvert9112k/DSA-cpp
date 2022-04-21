#include <bits/stdc++.h>
using namespace std;

void IterateReverse(queue<int> &q)
{
    stack<int> st;
    while (!q.empty())
        st.push(q.top()), q.pop();
    while (!st.empty())
        q.push(st.top()), st.pop();
}

void Recursive(queue<int> &q)
{
    if (q.empty())
        return;
    int x = q.front();
    q.pop();
    Recursive(q);
    q.push(x);
}
 
int main()

{
    queue<int> q;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        q.push(x);
    }
    IterativeReverse(queue);
    return 0;
}