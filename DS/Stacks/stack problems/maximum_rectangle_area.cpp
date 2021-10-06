#include<bits/stdc++.h>
using namespace std;
// problem statement
// Find the largest rectangular area possible in a given histogram where the largest rectangle can be made of a number of contiguous bars. For simplicity, assume that all bars have the same width and the width is 1 unit, there will be N bars height of each bar will be given by the array arr.

vector<int> previoussmaller(vector<int>& arr)
{
    int n = arr.size();
    stack< pair<int,int> > stack;
    vector<int> temp(n);
    stack.push({arr[0],0});
    temp[0] = -1;
    for (int i = 1; i < n; i++) 
    {
        if(!stack.empty() and stack.top().first < arr[i])
            temp[i] = stack.top().second;
        else
        {
            while(!stack.empty() and stack.top().first >= arr[i])
                stack.pop();
            if(!stack.empty())
                temp[i] = stack.top().second;
            else
                temp[i] = -1;
        }
        stack.push({arr[i],i});
    }
    return temp;
} 

vector<int> nextsmaller(vector<int>& arr)
{
    int n = arr.size();
    stack< pair<int,int> > stack;
    vector<int> temp(n);
    stack.push({arr[n-1],n-1});
    temp[n-1] = n;
    for (int i = n-2; i>=0; i--) 
    {
        if(!stack.empty() and stack.top().first < arr[i])
            temp[i] = stack.top().second;
        else
        {
            while(!stack.empty() and stack.top().first >= arr[i])
                stack.pop();
            if(!stack.empty())
                temp[i] = stack.top().second;
            else
                temp[i] = n;
        }
        stack.push({arr[i],i});
    }
    return temp;
}   

int maxarea(vector<int>& arr)
{
    vector<int> ps = previoussmaller(arr);
    vector<int> ns = nextsmaller(arr);
    for(auto x : ps)
        cout << x << " ";
    cout << endl;
    for(auto y: ns)
        cout << y << " ";
    cout << endl;
    int ans = INT_MIN;
    int k;
    for (int i = 0; i < arr.size(); i++)
    {
        k = (ns[i] - ps[i] - 1) * arr[i];
        ans = max(ans, k);
    }
    return ans;
}
int main() 

{

    int n;
    cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    cout << maxarea(arr) << endl;
    return 0;

} 