// 1402. Reducing Dishes
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(vector<int>& satisfaction, int i, vector<int> &v)
{
    if(i==satisfaction.size())
    {
        // sort(v.begin(),v.end());
        int sum = 0;
        int t = 1;
        for(int i:v)
            sum += (t++ * i);

        return sum;
    }

    int a = solve(satisfaction,i+1,v);
    v.push_back(satisfaction[i]);
    int b = solve(satisfaction,i+1,v);
    v.pop_back();

    return max(a,b);
}
int maxSatisfaction(vector<int>& satisfaction) 
{
    vector<int> v;
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,v);
}

// Recursion (Better approach)
int solve(vector<int>& satisfaction, int i, int sum, int t)
{
    if(i==satisfaction.size())
        return sum;

    int a = solve(satisfaction,i+1,sum,t);
    sum += (t*satisfaction[i]);
    int b = solve(satisfaction,i+1,sum,t+1);

    return max(a,b);
}
int maxSatisfaction(vector<int>& satisfaction) 
{
    sort(satisfaction.begin(),satisfaction.end());
    return solve(satisfaction,0,0,1);
}

// Recursion + Memorization
int solve(vector<int>& satisfaction, int i, int sum, int t, vector<vector<int>> &dp)
{
    if(i==satisfaction.size())
        return sum;

    if(dp[i][t] != -1)
        return dp[i][t];

    int a = solve(satisfaction,i+1,sum,t,dp);
    sum += (t*satisfaction[i]);
    int b = solve(satisfaction,i+1,sum,t+1,dp);

    return dp[i][t] = max(a,b);
}
int maxSatisfaction(vector<int>& satisfaction) 
{
    sort(satisfaction.begin(),satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n,vector<int>(n+1,-1));
    return solve(satisfaction,0,0,1,dp);
}

// Tabulation
int maxSatisfaction(vector<int>& satisfaction) 
{
    sort(satisfaction.begin(),satisfaction.end());
    int n = satisfaction.size();
    vector<vector<int>> dp(n+1,vector<int>(n+1,0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int a = dp[i+1][j];
            int b = ((j+1)*satisfaction[i]) + dp[i+1][j+1]; //this (j+1) is a mystry

            dp[i][j] = max(a,b);
        }
    }

    return dp[0][0];
}

// Space Optimization - O(2*n)
int maxSatisfaction(vector<int>& satisfaction) 
{
    sort(satisfaction.begin(),satisfaction.end());
    int n = satisfaction.size();
    // vector<vector<int>> dp(n+1,vector<int>(n+1,0));
    vector<int> curr(n+1,0);
    vector<int> prev(n+1,0);

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i; j>=0; j--)
        {
            int a = prev[j];
            int b = ((j+1)*satisfaction[i]) + prev[j+1];

            curr[j] = max(a,b);
        }
        prev = curr;
    }

    return prev[0];
}

// Space Optimization further - O(n)
int maxSatisfaction(vector<int>& satisfaction) 
{
    sort(satisfaction.begin(),satisfaction.end());
    int n = satisfaction.size();
    vector<int> prev(n+1,0);

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=i; j++)
        {
            int a = prev[j];
            int b = ((j+1)*satisfaction[i]) + prev[j+1];

            prev[j] = max(a,b);
        }
    }

    return prev[0];
}