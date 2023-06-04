#include <bits/stdc++.h> 
int recursion(int ind,vector<int> &value,vector<int> &weight,int w)
{   
	if(ind == 0)
	{   
		/*We have only one item to robb, if the weight of the item is 
		less than the weight that can carray in bag then we take it, else we don't*/
		if(weight[0] <= w) return value[0];
		else return 0;
	}
	int notTaken = recursion(ind-1,value,weight,w);
	int taken = INT_MIN;
	if(weight[ind] <= w)
	   taken = value[ind] + recursion(ind-1,value,weight,w-weight[ind]);
	return max(notTaken,taken);
}
int memoization(int ind,vector<int> &value,vector<int> &weight,int w
,vector<vector<int>> &dp)
{   
	if(ind == 0)
	{   
		if(weight[0] <= w) return value[0];
		else return 0;
	}
	if(dp[ind][w] != -1) return dp[ind][w];
	int notTaken = memoization(ind-1,value,weight,w,dp);
	int taken = INT_MIN;
	if(weight[ind] <= w)
	   taken = value[ind] + memoization(ind-1,value,weight,w-weight[ind],dp);
	return dp[ind][w] = max(notTaken,taken);
}
int Tabulation(int n,vector<int> &value,vector<int> &weight,int maxWeight)
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,0));
	for(int i = weight[0]; i<=maxWeight; ++i) dp[0][i] = value[0];
	for(int i = 1; i<n; ++i)
	{
		for(int j = 0; j <= maxWeight; ++j)
		{
			int notTaken = dp[i-1][j];
			int taken = INT_MIN;
			if(weight[i] <= j)
			taken = value[i] + dp[i-1][j-weight[i]];
		    dp[i][j] = max(notTaken,taken);
		}
	}
	return dp[n-1][maxWeight];
} 
int spaceOptimization(int n,vector<int> &value,vector<int> &weight,int maxWeight)
{
	vector<int> curr(maxWeight+1,0),prev(maxWeight+1,0);
	for(int i = weight[0]; i<=maxWeight; ++i) prev[i] = value[0];
	for(int i = 1; i<n; ++i)
	{
		for(int j = 0; j <= maxWeight; ++j)
		{
			int notTaken = prev[j];
			int taken = INT_MIN;
			if(weight[i] <= j)
			taken = value[i] + prev[j-weight[i]];
		    curr[j] = max(notTaken,taken);
		}
		prev = curr;
	}
	return prev[maxWeight];
}  
int spaceOptimization2(int n,vector<int> &value,vector<int> &weight,int maxWeight)
{
	vector<int> prev(maxWeight+1,0);
	for(int i = weight[0]; i<=maxWeight; ++i) prev[i] = value[0];
	for(int i = 1; i<n; ++i)
	{
		for(int j = maxWeight; j >= 0; --j)
		{
			int notTaken = prev[j];
			int taken = INT_MIN;
			if(weight[i] <= j)
			taken = value[i] + prev[j-weight[i]];
		    prev[j] = max(notTaken,taken);
		}
	}
	return prev[maxWeight];
}  
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{   
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
    // return recursion(n-1,value,weight,maxWeight);
	// return memoization(n-1,value,weight,maxWeight,dp);
	// return Tabulation(n,value,weight,maxWeight);
    return spaceOptimization2(n,value,weight,maxWeight);
}  