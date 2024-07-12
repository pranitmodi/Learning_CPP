// 1039. Minimum Score Triangulation of Polygon
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, int j, vector<int> &values)
{
    if(i+2 == j)
        return values[i]*values[i+1]*values[j];

    if(i+1 == j)
        return 0;

    int mini = INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        int curr = values[i]*values[j]*values[k];
        int a = solve(i,k,values);
        int b = solve(k,j,values);

        int ans = a + b + curr;
        mini = min(ans,mini);
    }
    
    return mini;
}

// Recusrion + Memorization
int solve(int i, int j, vector<int> &values, vector<vector<int>> &dp)
{
    if(i+1 == j)
        return 0;

    if(dp[i][j]!=INT_MAX)
        return dp[i][j];

    int mini = INT_MAX;
    for(int k=i+1; k<j; k++)
    {
        int curr = values[i]*values[j]*values[k];
        int a = solve(i,k,values,dp);
        int b = solve(k,j,values,dp);

        int ans = a + b + curr;
        mini = min(ans,mini);
    }
    
    return dp[i][j] = mini;
}
int minScoreTriangulation(vector<int>& values) 
{
    int i=0;
    int j=values.size();

    vector<vector<int>> dp(j,vector<int>(j,INT_MAX));
    return solve(i,j-1,values,dp);    
}

// tabulation
int solve(vector<int> &v)
{
    int n = v.size();
    vector<vector<int>> dp(n,vector<int>(n,0));

    for(int i=n-1; i>=0; i--)
    {
        for(int j=i+2; j<n; j++) // why j=i+2?
        {
            int mini = INT_MAX;
            for(int k=i+1; k<j; k++)
            {
                int curr = v[i]*v[j]*v[k];
                int ans = dp[i][k] + dp[k][j] + curr;
                mini = min(ans,mini);
            }

            dp[i][j] = mini;
        }
    }

    return dp[0][n-1];
}