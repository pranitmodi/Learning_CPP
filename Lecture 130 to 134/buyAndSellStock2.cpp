// 122. Best Time to Buy and Sell Stock II
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, vector<int>& prices)
{
    if(i == prices.size())
        return 0;

    int res = 0;
    while(i<prices.size())
    {
        int ans = 0;
        for(int j=i+1; j<prices.size(); j++)
        {
            if(prices[j]>=prices[i])
                ans = max(ans,prices[j]-prices[i] + solve(j+1,prices));
        }
        res = max(ans,res);
        i++;
    }

    return res;
}
int maxProfit(vector<int>& prices) {
    return solve(0,prices);
}

// Recursion + Memorization
int solve(int i, vector<int>& prices, int buy,vector<vector<int>> &dp)
{
    if(i == prices.size())
        return 0;

    if(dp[i][buy]!=-1)  
        return dp[i][buy];

    int profit = 0;
    if(buy)
    {
        int a = (-1*prices[i]) + solve(i+1,prices,0,dp);
        int b = solve(i+1,prices,1,dp);

        profit = max(a,b);
    }
    else
    {
        int a = prices[i] + solve(i+1,prices,1,dp);
        int b = solve(i+1,prices,0,dp);

        profit = max(a,b);
    }

    return dp[i][buy] = profit;
}
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    return solve(0,prices,1,dp);
}

// Tabulation
int maxProfit(vector<int>& prices) {
    vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
    // return solve(0,prices,1,dp);

    for(int i=prices.size()-1; i>=0; i--)
    {
        for(int j=0; j<=1; j++)
        {
            int profit = 0;
            if(j)
            {
                int a = (-1*prices[i]) + solve(i+1,prices,0,dp);
                int b = solve(i+1,prices,1,dp);

                profit = max(a,b);
            }
            else
            {
                int a = prices[i] + solve(i+1,prices,1,dp);
                int b = solve(i+1,prices,0,dp);

                profit = max(a,b);
            }

            dp[i][j] = profit;
        }
    }

    return dp[0][1];
}

// Space Optimization
int maxProfit(vector<int>& prices) {
    int a = 0;
    int b = 0;
    int c = 0;
    int d = 0;

    for(int i=prices.size()-1; i>=0; i--)
    {
        for(int j=0; j<=1; j++)
        {
            int profit = 0;
            if(j)
            {
                int x = (-1*prices[i]) + a;
                int y = b;

                d = max(x,y);
            }
            else
            {
                int x = prices[i] + b;
                int y = a;

                c = max(x,y);
            }
        }
        a = c;
        b = d;
    }
    return b;
}