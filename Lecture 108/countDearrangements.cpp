#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007

// Recursion
long long int countDerangements(int n) 
{
    if(n==1)
        return 0;

    if(n==2)
        return 1;

    return (((n-1)%MOD) * ((countDerangements(n-1)%MOD) + (countDerangements(n-2)%MOD)))%MOD;
}

// Recursion + Memorization
long long int solve(int n, vector<long long int> &dp) 
{
    if(n==1)
        return 0;

    if(n==2)
        return 1;

    if(dp[n]!=-1)
        return dp[n];

    return dp[n] = (((n-1)%MOD) * ((solve(n-1,dp)%MOD) + (solve(n-2,dp)%MOD)))%MOD;
}
long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    return solve(n,dp);
}

// Tabulation
long long int countDerangements(int n) {
    vector<long long int> dp(n+1,-1);
    dp[1] = 0;
    dp[2] = 1;

    for(int i=3; i<=n; i++)
    {
        dp[i] = (((i-1)%MOD) * (dp[i-1] + dp[i-2]))%MOD;
    }

    return dp[n];
}

// Space Optimisation
long long int countDerangements(int n) 
{
    long long int a = 0;
    long long int b = 1;

    for(int i=3; i<=n; i++)
    {
        long long int c = (((i-1)%MOD) * (b + a))%MOD;
        a = b;
        b = c;
    }

    return b;
}