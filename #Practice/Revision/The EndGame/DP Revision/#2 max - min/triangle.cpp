// 120. Triangle
#include <bits/stdc++.h>
using namespace std;

// Rec + Mem
int solve(int r, int c, vector<vector<int>>& triangle, vector<vector<int>>& dp)
{
    if(r == triangle.size())
        return 0;

    if(dp[r][c] != -1)
        return dp[r][c];

    int mini = INT_MAX;
    mini = min(mini,solve(r+1,c,triangle,dp));
    mini = min(mini,solve(r+1,c+1,triangle,dp));

    return dp[r][c] = triangle[r][c] + mini;
}
int minimumTotal(vector<vector<int>>& triangle) {
    vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
    return solve(0,0,triangle,dp);
}

// Tab
int minimumTotal(vector<vector<int>>& triangle) 
{
    vector<int> dp(triangle.size()+1,0);
    for(int r=triangle.size()-1; r>=0; r--)
        for(int c=0; c<=triangle[r].size()-1; c++)
            dp[c] = triangle[r][c] + min(dp[c],dp[c+1]);

    return dp[0];
}