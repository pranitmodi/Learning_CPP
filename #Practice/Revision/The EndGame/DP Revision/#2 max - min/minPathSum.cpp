// 64. Minimum Path Sum
#include <bits/stdc++.h>
using namespace std;

// Rec + Mem
bool check(int r, int c, int m, int n)
{
    if(r<=m && c<=n)
        return true;
    return false;
}
int solve(int r, int c, vector<vector<int>>& grid, vector<vector<int>> &dp)
{
    int m = grid.size()-1;
    int n = grid[0].size()-1;

    if(r == m && c == n)
        return grid[r][c];

    if(dp[r][c]!=-1)
        return dp[r][c];

    int mini = INT_MAX;
    if(check(r+1,c,m,n))
        mini = min(mini, solve(r+1,c,grid,dp));

    if(check(r,c+1,m,n))
        mini = min(mini, solve(r,c+1,grid,dp));

    return dp[r][c] = mini + grid[r][c];
}
int minPathSum(vector<vector<int>>& grid) {
    vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
    return solve(0,0,grid,dp);
}

