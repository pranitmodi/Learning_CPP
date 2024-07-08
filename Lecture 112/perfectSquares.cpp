// 279. Perfect Squares
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(vector<int> &nums, int n)
{
    if(n<0)
        return INT_MAX;
    
    if(n == 0)
        return 0;

    int mini = INT_MAX;
    for(int i=nums.size()-1; i>=0; i--)
    {
        if(n-nums[i]>=0)
        {
            int ans = solve(nums,n-nums[i]);
            if(ans!=INT_MAX)
            {
                mini = min(ans+1, mini);
            }
        }
    }

    return mini;
}

// Recusrion + Memorization
int solve(vector<int> &nums, int n, vector<int> &dp)
{
    if(n<0)
        return INT_MAX;
    
    if(n == 0)
        return 0;

    if(dp[n]!=INT_MAX)
        return dp[n];

    int mini = INT_MAX;
    for(int i=nums.size()-1; i>=0; i--)
    {
        if(n-nums[i]>=0)
        {
            int ans = solve(nums,n-nums[i],dp);
            if(ans!=INT_MAX)
            {
                mini = min(ans+1, mini);
            }
        }
    }

    return dp[n] = mini;
}
int numSquares(int n)
{
    vector<int> nums;
    int i=1;
    while((i*i) <= n)
    {
        nums.push_back(i*i);
        i++;
    }

    vector<int> dp(n+1,INT_MAX);
    return solve(nums,n,dp);
}

// Tabulation 
int solveTab(int n)
{
    vector<int> dp(n+1,INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=n; i++)
    {
        int mini = INT_MAX;
        for(int j=sqrt(n); j>=1; j--)
        {
            if(i-(j*j)>= 0 && dp[i-(j*j)] != INT_MAX)
                mini = min(dp[i-(j*j)]+1, mini);
        }
        dp[i] = mini;
    }
    return dp[n];
}