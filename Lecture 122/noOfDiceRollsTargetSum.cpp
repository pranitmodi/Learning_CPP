// 1155. Number of Dice Rolls With Target Sum
#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Recursion
int solve(int n, int k, int target)
{   
    if(target == 0 && n == 0)
        return 1;

    if(target == 0 || target < 0 || n <= 0)
        return 0;

    long long count = 0;
    for(int i=k; i>=1; i--)
    {
        int a = solve(n-1,k,target-i);
        count += a;
    }

    return count % MOD;
}

// Recursion + Memorization
int solve(int n, int k, int target, vector<vector<long long>> &dp)
{   
    if(target == 0 && n == 0)
        return 1;

    if(target == 0 || target < 0 || n <= 0)
        return 0;

    if(dp[n][target]!=-1)
        return dp[n][target];

    long long count = 0;
    for(int i=k; i>=1; i--)
    {
        int a = solve(n-1,k,target-i,dp);
        count += a;
    }

    return dp[n][target] = count % MOD;
}
int numRollsToTarget(int n, int k, int target) 
{
    vector<vector<long long>> dp(n+1,vector<long long>(target+1,-1));
    return solve(n,k,target,dp);
}

// Tabulation
int numRollsToTarget(int n, int k, int target) 
{
    vector<vector<long long>> dp(n+1,vector<long long>(target+1,0));
    dp[0][0] = 1;

    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            long long count = 0;
            for(int w=k; w>=1; w--)
            {
                int a = 0;
                if(j-w >= 0)
                    a = dp[i-1][j-w];
                count += a;
            }

            dp[i][j] = count % MOD;
        }
    }
    return dp[n][target];
}

// Space Optimization
int numRollsToTarget(int n, int k, int target) 
{
    vector<long long> curr(target+1,0);
    vector<long long> prev(target+1,0);

    prev[0] = 1;
    for(int i=1; i<=n; i++)
    {
        for(int j=0; j<=target; j++)
        {
            long long count = 0;
            for(int w=k; w>=1; w--)
            {
                int a = 0;
                if(j-w >= 0)
                    a = prev[j-w];
                count += a;
            }

            curr[j] = count % MOD;
        }
        prev = curr;
    }
    return prev[target];
}