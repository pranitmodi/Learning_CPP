#include <bits/stdc++.h> 
using namespace std;
// Only Recursion : TLE
int solve(vector<int> &num, int x)
{
    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;

    int mini = INT_MAX;
    for(int i=0; i<num.size(); i++)
    {
        int ans = solve(num,x-num[i]);

        if(ans != INT_MAX)
            mini = min(mini, ans+1);
    }

    return mini;
}

// Recursive + Memorization
int solve(vector<int> &num, int x, vector<int> &dp)
{
    if(x == 0)
        return 0;

    if(x<0)
        return INT_MAX;

    if(dp[x] != INT_MAX)
    {
        return dp[x];
    }
    
    for(int i=0; i<num.size(); i++)
    {
        int ans = solve(num,x-num[i],dp);

        if(ans != INT_MAX)
            dp[x] = min(dp[x], ans+1);
    }

    return dp[x];
}

// Tabulation
int solveTab(vector<int> &num, int x)
{
    vector<int> dp(x+1,INT_MAX);
    dp[0] = 0;

    for(int i=1; i<=x; i++)
    {
        for(int j=0; j<num.size(); j++)
        {
            if(i-num[j]>=0 && dp[i-num[j]]!=INT_MAX)
            {
                dp[i] = min(dp[i], dp[i-num[j]]+1);
            }
        }
    }

    if(dp[x] == INT_MAX)
        return -1;

    return dp[x];
}

int minimumElements(vector<int> &num, int x)
{
    vector<int> dp(x+1,INT_MAX);
    
    int ans = solve(num,x,dp);
    if(ans == INT_MAX)
        return -1;
    return ans;
}