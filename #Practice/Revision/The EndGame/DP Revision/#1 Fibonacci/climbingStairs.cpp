#include <bits/stdc++.h>
using namespace std;

// Recursion + Mem
int solve(int i, int n, vector<int> &dp)
{
    if(i>n)
        return 0;

    if(i == n)
        return 1;

    if(dp[i] != -1)
        return dp[i];

    int a = solve(i+1,n,dp);
    int b = solve(i+2,n,dp);

    return dp[i] = (a + b);
}

// Tab
int climbStairs(int n) 
{
    vector<int> dp(n+1,0);

    dp[n] = 1;
    for(int i=n-1; i>=0; i--)
    {
        int a = dp[i+1];
        int b = 0;
        if(i+2 <= n)
            b = dp[i+2];

        dp[i] = a + b;
    }

    return dp[0];
}

// Optimization
int climbStairs(int n) 
{
    int a = 1;
    int b = 1;
    for(int i=n-2; i>=0; i--)
    {
        int curr = a + b;
        a = b;
        b = curr;
    }
    return b;
}


int climbStairs(int n) {
    vector<int> dp(n+1,-1);
    return solve(0,n,dp);
}