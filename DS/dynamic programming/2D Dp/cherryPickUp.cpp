#include <bits/stdc++.h>
/*This is the recusion version of the code.*/
int recursion(int m,int n,int i,int j1,int j2,vector<vector<int>> &grid)
{   
    /*Out of bound case,if there is no path return some high negative value.*/
    if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) return -1e9;
    /*If the last row is reached
    1.There may be cases like both reach the same cell in last row, or different 
    cells.*/
    if(i == m-1)
    {
        if(j1 == j2) return grid[i][j1]; /*Reached same cell,count only once.*/
        else return grid[i][j1] + grid[i][j2]; /*REached different cells,take both*/
    }
    int maxi = INT_MIN;
    /*For each move alice takes,there are 3 possible moves of bob.
    Alice has 3 moves,hence there are 9 different states.
    Take the maximum among them*/
    for(int dj1 = -1; dj1 <= 1; ++dj1)
    {
        for(int dj2 = -1; dj2 <= 1; ++dj2)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1]; /*If current both are at same cell*/
            else value = grid[i][j1] + grid[i][j2];
            value += recursion(m,n,i+1,j1+dj1,j2+dj2,grid);
            maxi = max(maxi,value);
        }
    }
    return maxi;
}  
int memoization(int m,int n,int i,int j1,int j2,vector<vector<int>> &grid,
   vector<vector<vector<int>>> &dp)
{
    if(j1 < 0 || j2 < 0 || j1 >= n || j2 >= n) return -1e9;
    if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    if(i == m-1)
    {
        if(j1 == j2) return grid[i][j1]; 
        else return grid[i][j1] + grid[i][j2]; 
    }
    int maxi = INT_MIN;
    for(int dj1 = -1; dj1 <= 1; ++dj1)
    {
        for(int dj2 = -1; dj2 <= 1; ++dj2)
        {
            int value = 0;
            if(j1 == j2) value = grid[i][j1]; 
            else value = grid[i][j1] + grid[i][j2];
            value += memoization(m,n,i+1,j1+dj1,j2+dj2,grid,dp);
            maxi = max(maxi,value);
        }
    }
    return dp[i][j1][j2] = maxi;
} 
int Tabulation(vector<vector<int>> &grid)
{
    int m = grid.size(),n = grid[0].size();
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n)));
    /*Based on the base case,the tabulation filling changes.
    Here base excutes when i == m-1,so we starts filling from the bottom
    
    Now we are filling the bottom row,there may be 9 cases handling each
    of them.*/
    for(int j1 = 0; j1 < n; ++j1)
    {
        for(int j2 = 0; j2 < n; ++j2)
        {
            if(j1 == j2) dp[m-1][j1][j2] = grid[m-1][j2];
            else dp[m-1][j1][j2] = grid[m-1][j1] + grid[m-1][j2];
        }
    } 
    /*For converting into the tabulation,the for loop required should 
    be equal for loop to filling the dp array used in the memoization.
    
    After writing the for loops,copy the recurrence relation used in
    memoization or recursion.
    
    Return with the ans where we started our recursion call. */

    /*Three for loops are required to fill the dp array,hence three loops
    are used.*/
    for(int i = m-2; i>=0; --i)
    {
        for (int j1 = 0; j1 < n; ++j1) 
        {  
            for (int j2 = 0; j2 < n; ++j2) 
            {   
                /*Recurrece relation is copy pasted*/
                int maxi = INT_MIN;
                for(int dj1 = -1; dj1 <= 1; ++dj1)
                {
                    for(int dj2 = -1; dj2 <= 1; ++dj2)
                    {
                        int value = 0;
                        if(j1 == j2) value = grid[i][j1]; 
                        else value = grid[i][j1] + grid[i][j2];
                        if(j1+dj1 >= 0 && j1+dj1 < n && j2+dj2 >= 0 && j2+dj2 < n)
                             value += dp[i+1][j1+dj1][j2+dj2];
                        else 
                           value += -1e8;
                        maxi = max(maxi,value);
                    }
                }
                dp[i][j1][j2] = maxi;
            }
        }
    }
    return dp[0][0][n-1]; /*We started our recurison call with (0,0,n-1)
    so return that.*/
} 
int maximumChocolates(int r, int c, vector<vector<int>> &grid) {
    int m = grid.size(),n = grid[0].size();
    /*
    1.Here the alice and bob should move simulatenously.
    2.Whatever the move taken by the alice or bob they move the next row,in one move.
    3.Here is for the curr row they are in.
    4. j1 --> column of the alice, j2 --> column of the bob.
    5. Whenever j1 == j2,i.e they reach the same cell, so take it only once,else take
      cells of both alice and bob.
    */
    vector<vector<vector<int>>> dp(m,vector<vector<int>>(n,vector<int>(n,-1)));
    // return recursion(m,n,0,0,n-1,grid);
    // return memoization(m,n,0,0,n-1,grid,dp);
    return Tabulation(grid);
} 