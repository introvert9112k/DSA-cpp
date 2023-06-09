#include<bits/stdc++.h>
/*
Intution : 
1.We need to find the LCS in two strings.
2.suppose let's start from the end,f(ind1,ind2) indicates that what is the
LCS between s1[0,ind1] and s2[0,ind2].
3.f(n-1,m-1) indicates what is LCS between s1[0,n-1] and s2[0,m-1]. 
4.For the current index there are two cases possible
  i.Current Characters match 
  ii. They don't match.
5.If they match we can include it in our LCS,so decrease the both indexes to 
calculate the rest.
6.If they don't match,there will be two cases 
  i.If we move the ind1,then it may match with some value in ind2.
  ii.If we move the ind2,then it may match with some value in ind1.
  We want maximum LCS right,so we would take maximum of both the options.

   Time Complexity   -- O(2^n * 2^m)
   For string s2 there are 2^n possibiltes and s2 there are 2^m.
   It is near about exponential.
   Space Complexity -- O(n+m)
   If there is no LCS in both the strings,at each step there would be 
   two recursion calls,for the alternative index calls take maximum space.
   i.e O(n) for the s1 and O(m) for s2. Combined O(s1 + s2)  

*/
int recursion(int ind1,int ind2,string &s1,string &s2)
{   
	if(ind1 < 0 || ind2 < 0) return 0;
	if(s1[ind1] == s2[ind2]) 
	 return 1 + recursion(ind1-1,ind2-1,s1,s2);
    return max(recursion(ind1-1,ind2,s1,s2),recursion(ind1,ind2-1,s1,s2));
} 
/*
Here the varying indexes are ind1 and ind2
0 <= ind1 < n and 0 <= ind2 < m.
declaring a dp array to memoize.
/* 
   Time Complexity   -- O(n*m)
   There would be n*m different states.
   Space Complexity -- O(n*m) 
*/
int memoization(int ind1,int ind2,string &s1,string &s2,vector<vector<int>> &dp)
{
	if(ind1 < 0 || ind2 < 0) return 0;
	if(dp[ind1][ind2] != -1) return dp[ind1][ind2];
	if(s1[ind1] == s2[ind2]) 
	 return dp[ind1][ind2] = 1 + memoization(ind1-1,ind2-1,s1,s2,dp);
    return dp[ind1][ind2] = max(memoization(ind1-1,ind2,s1,s2,dp),
	memoization(ind1,ind2-1,s1,s2,dp)); 
} 
/*
In the base case indexes go -ve.But the dp array cannot hold the -ve indexes
So we should shift the indexes. That mean 
-1 corresponds to 0
0 corresponds to 1 and so on. Basically we should indexes by right by 1 step.
*/
int Tabulation(int n,int m,string &s1,string &s2)
{
    vector<vector<int>> dp(n+1,vector<int>(m+1,0));
	/*
	base case is when ind1 < 0 || ind2 < 0 return 0.
	When ind1 is -1 then ind2 can be anything from [0,m-1]
	upon shifting it changes when ind1 == 0,1 <= ind2 <= m.
	Similarly for ind2,when ind2 = 0, 1 <= ind1 <= n.
	*/
	for(int j = 1; j <= m; ++j) dp[0][j] = 0;
	for(int i = 1; i <= n; ++i) dp[i][0] = 0;
	for(int i = 1; i<=n; ++i)
	{
		for(int j = 1; j <=m; ++j)
		{
			if(s1[i-1] == s2[j-1]) dp[i][j] = 1 + dp[i-1][j-1];
            else 
			  dp[i][j] = max(dp[i][j-1] ,dp[i-1][j]);
		}
	}
	return dp[n][m];
}
int spaceOptimization(int n,int m,string &s1,string &s2)
{   
	vector<int> curr(m+1,0),prev(m+1,0);
    for(int j = 1; j <= m; ++j) prev[j] = 0;
	for(int i = 1; i<=n; ++i)
	{
		for(int j = 1; j <=m; ++j)
		{
			if(s1[i-1] == s2[j-1]) curr[j] = 1 + prev[j-1];
            else 
			   curr[j] = max(curr[j-1] ,prev[j]);
		}
		prev = curr;
	}
	return prev[m];
}
int lcs(string s, string t)
{
	int n = s.length(),m = t.length();
	vector<vector<int>> dp(n,vector<int>(m,-1));
	// return recursion(n-1,m-1,s,t);
	// return memoization(n-1,m-1,s,t,dp);
	// return Tabulation(n,m,s,t);
	return spaceOptimization(n,m,s,t);
}  