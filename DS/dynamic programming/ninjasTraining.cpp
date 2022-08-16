// See the takeuforward article for better understanding
#include <bits/stdc++.h>
using namespace std;
// Recursion.
int maxPoints(int day, int prevTask, vector<vector<int>> &points)
{
    if (day == 0)
    {
        int maxi = INT_MIN;
        for (int task = 0; task < 3; task++)
        {
            if (task != prevTask)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for (int task = 0; task < 3; task++)
    {
        if (task != prevTask)
        {
            int pointsGain = points[day][task] + maxPoints(day - 1, task, points);
            maxi = max(maxi, pointsGain);
        }
    }
    return maxi;
}

// Memoziation
int maxPoints(int day, int prevTask, vector<vector<int>> &points, vector<vector<int>> &dp)
{
    if (dp[day][prevTask] != -1)
        return dp[day][prevTask];
    if (day == 0)
    {
        int maxi = INT_MIN;
        for (int task = 0; task < 3; task++)
        {
            if (task != prevTask)
                maxi = max(maxi, points[0][task]);
        }
        return maxi;
    }
    int maxi = INT_MIN;
    for (int task = 0; task < 3; task++)
    {
        if (task != prevTask)
        {
            int pointsGain = points[day][task] + maxPoints(day - 1, task, points, dp);
            maxi = max(maxi, pointsGain);
        }
    }
    return dp[day][prevTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return maxPoints(n - 1, 3, points, dp);
}