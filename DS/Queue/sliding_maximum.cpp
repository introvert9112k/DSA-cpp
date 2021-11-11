#include <bits/stdc++.h>
using namespace std;

// problem statement
// given an array find the maximum in every window of size k

// ------------brute force approach--------------------
vector<int> method1(int arr[], int k, int n)
{
    vector<int> res;
    int mx = INT_MIN;
    for (int i = 0; i <= n - k; i++)
    {
        mx = INT_MIN;
        for (int j = 0; j < k; j++)
        {
            mx = max(mx, arr[i + j]);
        }
        res.push_back(mx);
    }
    return res;
    // T -- O((n-k)*k) --- O(n*k)
    // S ---O(1)
}
vector<int> method2(int arr[], int k, int n)
{
    // using priority_queue, in every window top element in priority_queue is the maximum element
    priority_queue<int> pq;
    vector<int> res;
    int i = 0;
    for (; i < k; i++)
        pq.push(arr[i]);
    for (; i < n; i++)
    {
        res.push_back(pq.top());
        pq.pop();
        pq.push(arr[i]);
    }
    res.push_back(pq.top());
    return res;
    // T ---- O(n*logk)
    // S --- O(k)
}
// Effiecent Approach
vector<int> method3(int arr[], int k, int n)
{
    // in deque we are storing only useful elements
    deque<int> dq;
    vector<int> res;
    int i = 0;
    for (; i < k; i++)
    {
        // removining the elements which are smaller than the current element,which are useless
        while (!dq.empty() and arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    for (; i < n; i++)
    {
        res.push_back(arr[dq.front()]);
        // removing the elements which are not in the window
        while (!dq.empty() and dq.back() <= i - k)
            dq.pop_back();
        // removining the elements which are smaller than the current element,which are useless
        while (!dq.empty() and arr[dq.back()] <= arr[i])
            dq.pop_back();
        dq.push_back(i);
    }
    res.push_back(arr[dq.front()]);
    return res;

    // T --- o(N)
    // S-----O(k)
}
int main()

{

    int n;
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin >> arr[i];
    int k;
    cin >> k;
    vector<int> res = method3(arr, k, n);
    for (auto x : res)
        cout << x << " ";
    return 0;
}