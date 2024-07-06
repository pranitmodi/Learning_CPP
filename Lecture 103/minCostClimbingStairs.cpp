// 746. Min Cost Climbing Stairs
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    // Recusrion + Memorization
    int fib(int n, vector<int> &dp, int i,vector<int>& cost)
    {
        if(i>=n)
            return 0;

        if(dp[i] != -1)
            return dp[i];

        int a = fib(n,dp,i+1,cost);
        int b = fib(n,dp,i+2,cost);

        int c = min(a,b);
        dp[i] = cost[i] + c;
        return dp[i];
    }

    // Tabulation
    int fib2(int n, vector<int>& cost)
    {
        int n = cost.size();
        vector<int> dp(n+1);

        dp[0] = cost[0];
        dp[1] = cost[1];

        for(int i=2; i<n; i++)
        {
            dp[i] = min(dp[i-1],dp[i-2]) + cost[i];
        }

        dp[n] = min(dp[n-1],dp[n-2]);
        return dp[n];
    }

    // Space Optimization
    int fib3(vector<int> &cost)
    {
        int n = cost.size();
        int a = cost[0];
        int b = cost[1];

        for(int i=2; i<n; i++)
        {
            int c = min(a,b) + cost[i];
            a = b;
            b = c;
        }

        return min(a,b);
    }
    int minCostClimbingStairs(vector<int>& cost) 
    {
        int n = cost.size();   
        vector<int> dp(n+1,-1);
        cout << min(fib(n,dp,0,cost),fib(n,dp,1,cost));

        cout << fib2(n,cost);

        cout << fib3(cost);
    }
};