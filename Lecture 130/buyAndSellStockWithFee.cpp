// 714. Best Time to Buy and Sell Stock with Transaction Fee
#include <bits/stdc++.h>
using namespace std;

// Recusrion + Memorization
int solve(int i, vector<int>& prices, int buy, int fee, vector<vector<int>> &dp)
{
    if(i == prices.size())
        return 0;

    if(dp[i][buy]!=-1)
        return dp[i][buy];

    if(buy)
    {
        int a = (-1*prices[i]) + solve(i+1,prices,0,fee,dp);
        int b = solve(i+1,prices,1,fee,dp);
        return dp[i][buy] = max(a,b);
    }
    else
    {
        int a = prices[i]-fee + solve(i+1,prices,1,fee,dp);
        int b = solve(i+1,prices,0,fee,dp);
        return dp[i][buy] = max(a,b);
    }
}
int maxProfit(vector<int>& prices, int fee) {
    vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
    return solve(0,prices,1,fee,dp);
}

// Space Optimization
int maxProfit(vector<int>& prices, int fee) {
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
                int x = prices[i] - fee + b; // only -fee was to be added
                int y = a;

                c = max(x,y);
            }
        }
        a = c;
        b = d;
    }
    return b;
}