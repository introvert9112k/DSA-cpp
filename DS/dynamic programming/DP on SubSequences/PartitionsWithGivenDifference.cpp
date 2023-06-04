#include <bits/stdc++.h> 
/*Note Here zero contains in the array.*/

/*Intution : 
1. Given S1-S2 = D. --- (equation 1)
We know that totalSum = (S1+S2) -- (equation 2)
There are two cases,we can eliminate the S2 or S1.

Case 1: Eliminating the S2.
S1-(totalSum-S1) = D
2S1 = (totalSum + D)
So S1 = (totalSum + D)/2
So we need to find the count of subsequenes whose sum is S1. 

Case 2 : Eliminating the S1
totalSum - S2 -S2 =D;
S2 = (totalSum -D)/2
So question boils down to count the subsequences whose sum is S2.

Now which one to consider between them.
We know that in the Tabulation we would declare a 2D array dp[n][sum]
if sum = (totalSum + D)/2 it would take higher space than (totalSum-D)/2
So try to eliminate the S1.
*/
int mod = 1e9+7;
int recursion(int ind,int sum,vector<int> &arr)
{
    if(ind == 0)
    {   
        /*If sum is zero and the first value is zero,then there will be two cases,
        taking it and not taking it,because taking or not taking do not alter the sum*/
        if(sum == 0 && arr[0] == 0 ) return 2;
        /*If sum is 0 and arr[0] != 0 then there is only 1 case not taking it,
        then only sum would not be altered.if sum == arr[0] then it must taken
        so there is also 1 case.*/
        if(sum == 0 || sum == arr[0] ) return 1;
        /*Rest of the cases return 0*/
        return 0;
    }
    int notTaken = recursion(ind-1,sum,arr);
    int taken = 0;
    if(arr[ind] <= sum)
       taken = recursion(ind-1,sum-arr[ind],arr);
    return (notTaken + taken)%mod;
} 
int memoization(int ind,int sum,vector<int> &arr,vector<vector<int>> &dp)
{
    if(ind == 0)
    {   
        /*If sum is zero and the first value is zero,then there will be two cases,
        taking it and not taking it,because taking or not taking do not alter the sum*/
        if(sum == 0 && arr[0] == 0 ) return 2;
        /*If sum is 0 and arr[0] != 0 then there is only 1 case not taking it,
        then only sum would not be altered.if sum == arr[0] then it must taken
        so there is also 1 case.*/
        if(sum == 0 || sum == arr[0] ) return 1;
        /*Rest of the cases return 0*/
        return 0;
    }
    if(dp[ind][sum] != -1) return dp[ind][sum];
    int notTaken = memoization(ind-1,sum,arr,dp);
    int taken = 0;
    if(arr[ind] <= sum)
       taken = memoization(ind-1,sum-arr[ind],arr,dp);
    return dp[ind][sum] = (notTaken + taken)%mod;
} 
int Tabulation(int n,int sum,vector<int> &arr)
{   
    vector<vector<int>> dp(n,vector<int>(sum+1,0));
    /*Base case is when ind == 0.when ind == 0 there is only one element present in 
    array.Then three cases are possible.
    case 1 : arr[0] == 0
    case 2 : arr[0] != 0

    if arr[0] == 0 what is the case of getting sum zero, (taking ,not taking)
    so dp[0][0] = 2
    if(arr[0] != 0) then what is the case of getting sum zero,i.e not taking it
    dp[0][0] = 1
    if arr[0] != 0 then what is the case of getting sum == arr[0] 
    dp[0][arr[0]] = 1
    */
    if(arr[0] == 0) dp[0][0] = 2;
    else dp[0][0] = 1;
    if(arr[0] != 0 && arr[0] <= sum) dp[0][arr[0]] = 1;
    for(int i = 1; i<n; ++i)
    {
        for(int j = 0; j <= sum; ++j)
        {
            int notTaken = dp[i-1][j];
            int taken = 0;
            if(arr[i] <= j)
               taken = dp[i-1][j-arr[i]];
            dp[i][j] = (notTaken + taken)%mod;
        }
    }
    return dp[n-1][sum];
} 
int countPartitions(int n, int d, vector<int> &arr) {
    int totalSum = 0;
    for(auto val : arr) totalSum += val;
    /*If D > totalSum then there exists no subsets whose difference is D.
    As all the numbers in arr are integers,so for the valid subset sum (totalSum-D) 
    should be divided by 2*/
    if( (totalSum-d) < 0 || (totalSum-d)%2 != 0) return 0;
    int target = (totalSum-d)/2;
    vector<vector<int>> dp(n,vector<int>(target+1,-1));
    // return recursion(n-1,target,arr);
    // return memoization(n-1,target,arr,dp);
    return Tabulation(n,target,arr);
} 


/**/