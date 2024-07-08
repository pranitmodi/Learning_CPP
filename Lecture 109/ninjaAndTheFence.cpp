#include <bits/stdc++.h> 
using namespace std;
#define MOD 1000000007

int add(int a, int b)
{
    return ((a%MOD) + (b%MOD))%MOD;
}
int mul(int a, int b)
{
    return ((a%MOD) * 1LL * (b%MOD))%MOD;
}

// Recursion
int numberOfWays(int n, int k) {
    if(n == 1)
        return k;

    if(n == 2)
        return add(k,mul(k,k-1));

    return mul(add(numberOfWays(n-1,k),numberOfWays(n-2,k)),(k-1));
}

// Recursion + Memorization
int solve(int n, int k, vector<int> &dp) {
    if(n == 1)
        return k;

    if(n == 2)
        return add(k,mul(k,k-1));

    if(dp[n] != -1)
        return dp[n];

    dp[n] = mul(add(solve(n-1,k,dp),solve(n-2,k,dp)),(k-1));
    return dp[n];
}
int numberOfWays(int n, int k) {
    vector<int> dp(n + 1, -1);
    return solve(n, k, dp);
}

// Tabulation
int numberOfWays(int n, int k) 
{
    vector<int> dp(n + 1, -1);
    dp[1] = k;
    dp[2] = add(k,mul(k,k-1));

    for(int i=3; i<=n; i++)
    {
        dp[i] = mul(add(dp[i-1],dp[i-2]),(k-1));
    }

    return dp[n];
}

// Space Optimization
int numberOfWays(int n, int k) 
{
    int a = k;
    int b = add(k,mul(k,k-1));

    for(int i=3; i<=n; i++)
    {
        int c = mul(add(b,a),(k-1));
        a = b;
        b = c;
    }

    return b;
}