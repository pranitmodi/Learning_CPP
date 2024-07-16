// 375. Guess Number Higher or Lower II
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int s, int e)
{
    if(s >= e)
        return 0;

    int mini = INT_MAX;
    for(int i=s; i<=e; i++)
        mini = min(mini, i + max(solve(s,i-1),solve(i+1,e)));

    return mini;
}
int getMoneyAmount(int n) {
    return solve(1,n);
}

// Recusrion + Memorization
int solve(int s, int e, vector<vector<int>> &dp)
{
    if(s >= e)
        return 0;

    if(dp[s][e]!=-1)
        return dp[s][e];

    int mini = INT_MAX;
    for(int i=s; i<=e; i++)
    {
        mini = min(mini, i + max(solve(s,i-1,dp),solve(i+1,e,dp)));
    }
    return dp[s][e] = mini;
}
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+1,vector<int>(n+1,-1));
    return solve(1,n,dp);
}

// Tabulation
int getMoneyAmount(int n) {
    vector<vector<int>> dp(n+2,vector<int>(n+2,0));
    // return solve(1,n,dp);
    for(int s=n; s>=1; s--)
    {
        for(int e=s; e<=n; e++) // starts with e=s
        {
            if(s==e)
                continue;
            else
            {
                int mini = INT_MAX;
                for(int i=s; i<=e; i++)
                {
                    mini = min(mini, i + max(dp[s][i-1],dp[i+1][e]));
                }
                dp[s][e] = mini;
            }
        }
    }

    return dp[1][n];
}