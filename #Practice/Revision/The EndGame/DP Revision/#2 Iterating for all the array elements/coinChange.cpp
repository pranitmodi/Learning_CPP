// 322. Coin Change
#include <bits/stdc++.h>
using namespace std;

// Rec + Mem
int solve(vector<int>& coins, int amt, vector<int> &dp)
{
    if(amt == 0)
        return 0;

    if(dp[amt] != -1)
        return dp[amt];

    int mini = INT_MAX;
    for(int i=0; i<coins.size(); i++)
    {
        if(amt-coins[i] >= 0 && solve(coins,amt-coins[i],dp)!=INT_MAX)
            mini = min(mini,solve(coins,amt-coins[i],dp) + 1);
    }

    return dp[amt] = mini;
}

// Tab
int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount+1,INT_MAX);
    dp[0] = 0;
    for(int i=1; i<=amount; i++)
    {
        int mini = INT_MAX;
        for(int j=0; j<coins.size(); j++)
        {
            if(i - coins[j] >= 0 && dp[i-coins[j]]!=INT_MAX)
                mini = min(mini,dp[i-coins[j]] + 1);
        }
        dp[i] = mini;
    }

    if(dp[amount] == INT_MAX)
        return -1;
    return dp[amount];
}

int coinChange(vector<int>& coins, int amount) 
{
    vector<int> dp(amount+1,-1);
    int ans = solve(coins,amount,dp);
    if(ans == INT_MAX)
        return -1;
    return ans;
}

