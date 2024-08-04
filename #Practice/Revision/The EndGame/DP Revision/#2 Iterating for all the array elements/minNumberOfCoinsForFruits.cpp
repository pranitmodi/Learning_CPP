// 2944. Minimum Number of Coins for Fruits
#include <bits/stdc++.h>
using namespace std;

// Recusrion
int solve(vector<int>& prices, int i)
{
    if(i>=prices.size())
        return 0;

    int mini = INT_MAX;
    for(int w=1; w<=(i+1); w++)
    {
        int a = solve(prices,i+w+1);
        int b = solve(prices,i+w);

        mini = min(mini,min(a,b));
    }

    return prices[i] + mini;
}
int minimumCoins(vector<int>& prices) {
    return solve(prices,0);
}

// Recursion + Mem
int solve(vector<int>& prices, int i, vector<int> &dp)
{
    if(i>=prices.size())
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    for(int w=1; w<=(i+1); w++)
    {
        int a = solve(prices,i+w+1,dp);
        int b = solve(prices,i+w,dp);

        mini = min(mini,min(a,b));
    }

    return dp[i] = prices[i] + mini;
}
int minimumCoins(vector<int>& prices) {
    vector<int> dp(prices.size()+1,-1);
    return solve(prices,0,dp);
}

// Tab
int minimumCoins(vector<int>& prices) {
    vector<int> dp(prices.size()+1,0);

    for(int i=prices.size()-1; i>=0; i--)
    {
        int mini = INT_MAX;
        for(int w=1; w<=(i+1); w++)
        {
            if((i+w+1)<=prices.size())
                mini = min(mini,dp[i+w+1]);

            if((i+w)<=prices.size())
                mini = min(mini,dp[i+w]);
        }
        dp[i] = prices[i] + mini;
    }
    return dp[0];   
}