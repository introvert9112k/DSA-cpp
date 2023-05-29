#include <bits/stdc++.h> 
/*
 Time complexity : O(2^n)
 For each ind there are two possible options.
 Space Complexity : O(n)
 Recursion stack space
*/
bool recursion(int ind,int k,vector<int>&arr)
{  
    /*If any movment the target becomes zero,that mean we found a subset/subsequence
    whose sum is k. So return true.*/
    if(k == 0) return true;
    /*If we reach the index 0,that mean only 1 element left in our array and k is still
    non zero,in order to exists a subset with sum k,arr[0] must be equal to k*/
    if(ind == 0) return arr[0] == k;
    /*There are two cases
    1.Include currrent value i.e arr[ind] in our subset.
    2.Exclude current  value i.e arr[ind] in our subset.*/
    /*If don't pick the current value,then k don't get reduced*/
    bool nonPick = recursion(ind-1,k,arr);
    /*Now we need to consider the current value. 
    We only consider the current value,when arr[ind] <= k. If arr[ind] > k then
    taking it no use becuase we never gonna get zero ( k-arr[ind] < 0 ) if we consider
    it.So consider pick option only when arr[ind] <= k*/
    bool pick = false;
    if(arr[ind] <= k)
       pick = recursion(ind-1,k-arr[ind],arr);
    /*If any of the two choices return true,then return true*/
    return pick | nonPick; 
}
/*
  Time Complexity   : O(n*k)
  Space Complexity  : O(n*K) + O(n)
  There are n*k different states.
*/
bool memoization(int ind,int k,vector<int> &arr,vector<vector<bool>> &dp)
{
    if(k == 0) return true;
    if(ind == 0) return arr[0] == k;
    if(dp[ind][k]) return dp[ind][k];
    bool nonPick = memoization(ind-1,k,arr,dp);
    bool pick = false;
    if(arr[ind] <= k)
      pick = memoization(ind-1,k-arr[ind],arr,dp);
    return dp[ind][k] = nonPick | pick;
}
bool Tabulation(int n,int target,vector<int> &arr) 
{
    vector<vector<bool>> dp(n,vector<bool>(target+1,false));
    /*Tabulation : start from the base and move to top
    1. First base case is when k == 0 we should return false.
    k can be become zero at any index from 0 -- > n-1. so dp[i][0] is  true for i(0-->n)
    2.Second base case is when ind == 0,when ind == 0,only dp[0][arr[0]] would be true.
    One cache is here that if arr[0] > k then it goes out of bond. so we need to 
    take care of it.
    */
    for(int i = 0; i<n; ++i) dp[i][0] = true;
    if(arr[0] <= target) dp[0][arr[0]] = true;
    /*Write the for loops to build the dp array*/
    for(int i = 1; i < n; ++i)
    {
        for(int k = 1; k <= target; ++k)
        {  
            /*Copy paste the recursion*/
            bool nonPick = dp[i-1][k];
            bool pick = false;
            if(arr[i] <= k) 
                pick = dp[i-1][k-arr[i]];
            dp[i][k] = pick | nonPick;
        }
    }
    /*Return with the states where recursion is called intially*/
    return dp[n-1][target];
}
bool spaceOptimization(int n,int target,vector<int> &arr)
{  
    /*As there is dp[i-1] and dp[i] in the tabulation,so it can be space optimized.
    The condition 
     for(int i = 0; i<n; ++i) dp[i][0] = true;
    is true for all the rows first element.
    As the i starts from 1 in the tabulation,so curr is for the 1st row and prev is
    for the 0th row.
    so set curr[0] = prev[0] = true.

    if(arr[0] <= target) dp[0][arr[0]] = true;
    as dp[0] mean prev, replace dp[0] with prev.
    */
    vector<bool> prev(target+1);
    prev[0] = true;
    if(arr[0] <= target) prev[arr[0]] = true;
    for(int i = 1; i <n; ++i)
    {   
        vector<bool> curr(target+1);
        curr[0] = true;
        for(int k = 1; k <= target; ++k)
        {
            bool nonPick = prev[k];
            bool pick = false;
            if(arr[i] <= k) 
                pick = prev[k-arr[i]];
            curr[k] = pick | nonPick;
        }
        prev = curr;
    }
    return prev[target];
} 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<bool>> dp(n,vector<bool>(k+1,false));
    // return recursion(n-1,k,arr);
    // return memoization(n-1,k,arr,dp);
    // return Tabulation(n,k,arr);
    return spaceOptimization(n,k,arr);
}  