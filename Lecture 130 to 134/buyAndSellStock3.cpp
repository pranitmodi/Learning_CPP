// 123. Best Time to Buy and Sell Stock III
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, bool buy, int limit, vector<int>& prices)
{
    if(i == prices.size() || limit == 0)
        return 0;

    if(buy)
    {
        int a = (-1 * prices[i]) + solve(i+1,0,limit,prices);
        int b = solve(i+1,1,limit,prices);
        return max(a,b);
    }
    else
    {
        int a = prices[i] + solve(i+1,1,limit-1,prices);
        int b = solve(i+1,0,limit,prices);
        return max(a,b);
    }
}
int maxProfit(vector<int>& prices) 
{
    return solve(0,1,2,prices);
}

// Recusrion + Memorization
int solve(int i, bool buy, int limit, vector<int>& prices, vector<vector<vector<int>>> &dp)
{
    if(i == prices.size() || limit == 0)
        return 0;

    if(dp[i][buy][limit]!=-1)
        return dp[i][buy][limit];

    if(buy)
    {
        int a = (-1 * prices[i]) + solve(i+1,0,limit,prices,dp);
        int b = solve(i+1,1,limit,prices,dp);
        return dp[i][buy][limit] = max(a,b);
    }
    else
    {
        int a = prices[i] + solve(i+1,1,limit-1,prices,dp);
        int b = solve(i+1,0,limit,prices,dp);
        return dp[i][buy][limit] = max(a,b);
    }
}
int maxProfit(vector<int>& prices) 
{
    vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(3,-1)));
    return solve(0,1,2,prices,dp);
}

// Tabulation
int maxProfit(vector<int>& prices) 
{
    vector<vector<vector<int>>> dp(prices.size()+1,vector<vector<int>>(2,vector<int>(3,0)));

    for(int i=prices.size()-1; i>=0; i--)
    {
        for(int j=0; j<=1; j++)
        {
            for(int k=2; k>0; k--)
            {
                if(j)
                {
                    int a = (-1 * prices[i]) + dp[i+1][0][k];
                    int b = dp[i+1][1][k];
                    dp[i][j][k] = max(a,b);
                }
                else
                {
                    int a = prices[i] + dp[i+1][1][k-1];
                    int b = dp[i+1][0][k];
                    dp[i][j][k] = max(a,b);
                }
            }
        }
    }

    return dp[0][1][2];
}

// Space Optimization
int maxProfit(vector<int>& prices) 
{
    vector<vector<int>> curr(2,vector<int>(3,0));
    vector<vector<int>> next(2,vector<int>(3,0));

    for(int i=prices.size()-1; i>=0; i--)
    {
        for(int j=0; j<=1; j++)
        {
            for(int k=2; k>0; k--)
            {
                if(j)
                {
                    int a = (-1 * prices[i]) + next[0][k];
                    int b = next[1][k];
                    curr[j][k] = max(a,b);
                }
                else
                {
                    int a = prices[i] + next[1][k-1];
                    int b = next[0][k];
                    curr[j][k] = max(a,b);
                }
            }
            next = curr;
        }
    }

    return next[1][2];
}
