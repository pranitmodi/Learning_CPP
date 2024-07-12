//
#include <bits/stdc++.h>
using namespace std;

// Recusrion
int solve(vector<int>& obstacles, int p, int l, int n)
{
    if(p == n-1)
        return 0;

    if(obstacles[p+1]!=l)
        return solve(obstacles,p+1,l,n);

    int mini = INT_MAX;
    for(int i=1; i<=3; i++)
    {
        if(i!=l && obstacles[p]!=i)
            mini = min(mini,1 + solve(obstacles,p,i,n));
    }

    return mini;
}

// Recursion + Memorization
int solve(vector<int>& obstacles, int p, int l, int n, vector<vector<int>> &dp)
{
    if(p == n-1)
        return 0;

    if(dp[p][l] != -1)
        return dp[p][l];

    if(obstacles[p+1]!=l)
        return dp[p][l] = solve(obstacles,p+1,l,n,dp);

    int mini = n+2;
    for(int i=1; i<=3; i++)
    {
        if(i!=l && obstacles[p]!=i)
            mini = min(mini,1 + solve(obstacles,p,i,n,dp));
    }

    return dp[p][l] = mini;
}
int minSideJumps(vector<int>& obstacles) 
{
    int n = obstacles.size();
    vector<vector<int>> dp(n,vector<int>(4,-1));
    return solve(obstacles,0,2,n,dp);
}

// Tabulation
int minSideJumps(vector<int>& obstacles) 
{
    int n = obstacles.size();
    vector<vector<int>> dp(4,vector<int>(n,INT_MAX));
    // p=position, l=lane

    dp[0][n-1] = 0;
    dp[1][n-1] = 0;
    dp[2][n-1] = 0;
    dp[3][n-1] = 0;
    for(int p=n-2; p>=0; p--)
    {
        for(int l=1; l<=3; l++)
        {
            if(obstacles[p+1]!=l)
            {
                dp[l][p] = dp[l][p+1];
            }
            else
            {
                int mini = n+2;
                for(int i=1; i<=3; i++)
                {
                    if(i!=l && obstacles[p]!=i)
                        mini = min(mini,1 + dp[i][p+1]);
                }

                dp[l][p] = mini;
            }
        }
    }

    return min(dp[2][0], 1 + min(dp[1][0],dp[3][0]));
}

// Sapce Optimization - O(8) ~ O(1)
int minSideJumps(vector<int>& obstacles) 
{
    int n = obstacles.size();
    // p=position, l=lane
    vector<int> curr(4,INT_MAX);
    vector<int> next(4,0);

    for(int p=n-2; p>=0; p--)
    {
        for(int l=1; l<=3; l++)
        {
            if(obstacles[p+1]!=l)
                curr[l] = next[l];
            else
            {
                int mini = n+2;
                for(int i=1; i<=3; i++)
                {
                    if(i!=l && obstacles[p]!=i)
                        mini = min(mini,1 + next[i]);
                }
                curr[l] = mini;
            }
        }
        next = curr;
    }
    return min(curr[2], 1 + min(curr[1],curr[3]));
}