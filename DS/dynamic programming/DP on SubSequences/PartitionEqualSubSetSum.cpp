class Solution {
bool recursion(int ind,int k,vector<int>&nums)
{
    if(k == 0) return true;
    if(ind == 0) return nums[ind] == k;
    bool notPick = recursion(ind-1,k,nums);
    bool pick = false;
    if(nums[ind] <= k)
       pick = recursion(ind-1,k-nums[ind],nums);
    return pick || notPick;
}
bool memoization(int ind,int k,vector<int>&nums,vector<vector<bool>> &dp)
{
    if(k == 0) return true;
    if(ind == 0) return nums[ind] == k;
    if(dp[ind][k]) return dp[ind][k];
    bool notPick = memoization(ind-1,k,nums,dp);
    bool pick = false;
    if(nums[ind] <= k)
       pick = memoization(ind-1,k-nums[ind],nums,dp);
    return dp[ind][k] = pick || notPick;
}
bool Tabulation(int n,int k,vector<int>&nums,vector<vector<bool>> &dp)
{   
    for(int i = 0; i<n; ++i) dp[i][0] = true;
    if(nums[0] <= k) dp[0][nums[0]] = true;
    for(int i = 1; i<n; ++i) 
    {
        for(int target = 1; target <= k; ++target)
        {
            bool notPick = dp[i-1][target];
            bool pick = false;
            if(nums[i] <= target) 
               pick = dp[i-1][target-nums[i]];
            dp[i][target] =  pick || notPick;
        }
    }
    return dp[n-1][k];
} 
bool spaceOptimization(int n,int k,vector<int>&nums)
{
    vector<int> prev(k+1,false);
    if(nums[0] <= k) prev[nums[0]] = true;
    for(int i = 1; i<n; ++i)
    {
        vector<int> curr(k+1,false);
        curr[0] = true;
        for(int target = 1; target <= k; ++target)
        {
            bool notPick = prev[target];
            bool pick = false;
            if(nums[i] <= target) 
               pick = prev[target-nums[i]];
            curr[target] =  pick || notPick;
        }
        prev = curr;
    }
    return prev[k];
}
public:
/*
Intution : 
1. If the totalSum is odd then we cannot split the array into two subsets of equal sum.
2. If totalSum is even,then if we found one subset then automatically left out elements forms another subset.
3. So our goal is to find if there exists any subset whose sum is totalSum/2.
4. This is the classic problem of DP [Subset Sum equal to target]
*/
    bool canPartition(vector<int>& nums) {
        int totalSum = 0,n = nums.size();
        for(auto num : nums) totalSum += num;
        if(totalSum&1) return false;
        else 
        {
            int target = totalSum/2;
            vector<vector<bool>> dp(n,vector<bool>(target+1,false));
            // return recursion(n-1,target,nums);
            // return memoization(n-1,target,nums,dp);
            // return Tabulation(n,target,nums,dp);
            return spaceOptimization(n,target,nums);
        }
    }
};