// 221. Maximal Square
#include <bits/stdc++.h>
using namespace std;

// Recusrion
int solve(vector<vector<char>>& matrix, int i, int j, int &maxi)
{
    if(i>=matrix.size() || j>=matrix[0].size())
        return 0;

    int right = solve(matrix,i,j+1,maxi);
    int diag = solve(matrix,i+1,j+1,maxi);
    int left = solve(matrix,i+1,j,maxi);

    if(matrix[i][j] == '1')
    {
        int ans = 1 + min(left, min(right,diag));
        maxi = max(ans,maxi);
        return ans;
    }
    else
        return 0;
}
int maximalSquare(vector<vector<char>>& matrix) 
{
    int maxi = 0;
    int ans = solve(matrix,0,0,maxi);
    return maxi*maxi;
}

// Recursion + Memorization
int solve(vector<vector<char>>& matrix, int i, int j, int &maxi,vector<vector<int>> &dp)
{
    if(i>=matrix.size() || j>=matrix[0].size())
        return 0;

    if(dp[i][j] != -1)
        return dp[i][j];

    int right = solve(matrix,i,j+1,maxi,dp);
    int diag = solve(matrix,i+1,j+1,maxi,dp);
    int left = solve(matrix,i+1,j,maxi,dp);

    if(matrix[i][j] == '1')
    {
        dp[i][j] = 1 + min(left, min(right,diag));
        maxi = max(dp[i][j],maxi);
    }
    else
        dp[i][j] = 0;

    return dp[i][j];
}
int maximalSquare(vector<vector<char>>& matrix) 
{
    int maxi = 0;
    vector<vector<int>> dp(matrix.size(),vector<int>(matrix[0].size(),-1));
    int a = solve(matrix,0,0,maxi,dp);
    return maxi*maxi;
}

// Tabulation
int maximalSquare(vector<vector<char>>& matrix) 
{
    int maxi = 0;
    vector<vector<int>> dp(matrix.size()+1,vector<int>(matrix[0].size()+1,0));

    for(int i=matrix.size()-1; i>=0; i--)
    {
        for(int j=matrix[0].size()-1; j>=0;  j--)
        {
            int right = dp[i][j+1];
            int diag = dp[i+1][j+1];
            int left = dp[i+1][j];

            if(matrix[i][j] == '1')
            {
                dp[i][j] = 1 + min(left, min(right,diag));
                maxi = max(dp[i][j],maxi);
            }
            else
                dp[i][j] = 0;
        }
    }
    return maxi*maxi;
}