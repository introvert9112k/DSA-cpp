#include <bits/stdc++.h>
using namespace std;

// given an array we should find the nearest previous elements which are smallwer and greater than the given element
// given an array we should find the nearst next elements which are smallwer and greater than the given element
// basically we should find
// previous smaller
// previous greater
// next smaller
// next greater
void previoussmaller(vector<int> &arr)
{
    stack<int> stack;
    stack.push(arr[0]);
    // first push the first element into the stack
    // there is no previous smaller element than the first element so cout -1
    cout << -1 << " ";
    // now iterate from the 1st position to till end of the vector
    for (int i = 1; i < arr.size(); i++)
    {
        // if top element of stack is lesser than current element then print it,because it is the nearest previous smaller element
        if (!stack.empty() and stack.top() < arr[i])
            cout << stack.top() << " ";
        // else pop the elements of the stack until you reach the smaller element than current element
        else
        {
            while (!stack.empty() and stack.top() >= arr[i])
                stack.pop();
            if (stack.empty())
                cout << -1 << " ";
            else

                cout << stack.top() << " ";
        }
        // push the current element into stack in every iteration
        stack.push(arr[i]);
    }
    cout << endl;
}

void previousgreater(vector<int> &arr)
{
    stack<int> stack;
    stack.push(arr[0]);
    cout << -1 << " ";
    for (int i = 1; i < arr.size(); i++)
    {
        if (!stack.empty() and stack.top() > arr[i])
            cout << stack.top() << " ";
        else
        {
            while (!stack.empty() and stack.top() <= arr[i])
            {
                stack.pop();
            }
            if (stack.empty())
                cout << -1 << " ";
            else
                cout << stack.top() << " ";
        }
        stack.push(arr[i]);
    }
    cout << endl;
}

void nextgreater(vector<int> &arr)
{
    stack<int> stack;
    stack.push(arr[arr.size() - 1]);
    vector<int> temp(arr.size());
    temp[arr.size() - 1] = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (!stack.empty() and stack.top() > arr[i])
            temp[i] = stack.top();
        else
        {
            while (!stack.empty() and stack.top() <= arr[i])
                stack.pop();
            if (stack.empty())
                temp[i] = -1;
            else
                temp[i] = stack.top();
        }
        stack.push(arr[i]);
    }
    for (auto x : temp)
        cout << x << " ";
    cout << endl;
} 
void nextsmaller(vector<int> &arr)
{
    stack<int> stack;
    stack.push(arr[arr.size() - 1]);
    vector<int> temp(arr.size());
    temp[arr.size() - 1] = -1;
    for (int i = arr.size() - 2; i >= 0; i--)
    {
        if (!stack.empty() and stack.top() < arr[i])
            temp[i] = stack.top();
        else
        {
            while (!stack.empty() and stack.top() >= arr[i])
                stack.pop();
            if (stack.empty())
                temp[i] = -1;
            else
                temp[i] = stack.top();
        }
        stack.push(arr[i]);
    }
    for (auto x : temp)
        cout << x << " ";
    cout << endl;
}
int main()

{
    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << "previous smaller elements " << endl;
    previoussmaller(arr);
    cout << "previous greater elements " << endl;
    previousgreater(arr);
    cout << "next greater elements " << endl;
    nextgreater(arr);
    cout << "next smaller elements " << endl;
    nextsmaller(arr);
    return 0;
}  