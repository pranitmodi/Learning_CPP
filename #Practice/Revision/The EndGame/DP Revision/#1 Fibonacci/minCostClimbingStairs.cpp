// 746. Min Cost Climbing Stairs
#include <bits/stdc++.h>
using namespace std;

// Rec + Mem
int solve(int i, int n, vector<int>& cost, vector<int> &dp)
{
    if(i >= n)
        return 0;

    if(dp[i] != -1)
        return dp[i];

    int mini = INT_MAX;
    mini = min(solve(i+1,n,cost,dp),solve(i+2,n,cost,dp)) + cost[i];
    return dp[i] = mini;
}

// Tab
int minCostClimbingStairs(vector<int>& cost) 
{
    vector<int> dp(cost.size()+1,-1);
    int n = cost.size();

    dp[n] = 0;
    for(int i=n-1; i>=0; i--)
    {
        dp[i] = dp[i+1];
        if(i+2 <= n)
            dp[i] = min(dp[i+1],dp[i+2]);
        dp[i] += cost[i];
    }

    return min(dp[0],dp[1]);
}

// Optimization
int minCostClimbingStairs(vector<int>& cost) {
    int n = cost.size();
    int b = 0;
    int a = 0;
    for(int i=n-1; i>=0; i--)
    {
        int curr = min(a,b) + cost[i];
        a = b;
        b = curr;
    }

    return min(a,b);
}

int minCostClimbingStairs(vector<int>& cost) {
    vector<int> dp(cost.size()+1,-1);
    return min(solve(0,cost.size(),cost,dp),solve(1,cost.size(),cost,dp));
}

