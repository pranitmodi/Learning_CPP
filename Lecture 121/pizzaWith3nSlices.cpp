// 
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, int end, vector<int>& slices, int k)
{
    if(k==0 || i>end)
        return 0;

    int a = slices[i] + solve(i+2,end,slices,k-1);
    int b = 0 + solve(i+1,end,slices,k);

    return max(a,b);
}
int maxSizeSlices(vector<int>& slices) 
{
    int n = slices.size();
    int k = n/3;

    int a = solve(0,n-2,slices,k);
    int b = solve(1,n-1,slices,k);
    return max(a,b);
}

// Recusrsion + Memorization
int solve(int i, int end, vector<int>& slices, int k, vector<vector<int>> &dp)
{
    if(k==0 || i>end)
        return 0;

    if(dp[i][k] != -1)
        return dp[i][k];

    int a = slices[i] + solve(i+2,end,slices,k-1,dp);
    int b = 0 + solve(i+1,end,slices,k,dp);

    return dp[i][k] = max(a,b);
}
int maxSizeSlices(vector<int>& slices) {
    int n = slices.size();
    int k = n/3;

    // case 1 - when person picks the 0th slice
    vector<vector<int>> dp(n,vector<int>(k+1,-1));
    int a = solve(0,n-2,slices,k,dp);

    // case 2 - when person picks any other slice
    vector<vector<int>> d1(n,vector<int>(k+1,-1));
    int b = solve(1,n-1,slices,k,d1);

    return max(a,b);
}
        
// Tabulation
int maxSizeSlices(vector<int>& slices) 
{
    int n = slices.size();
    int k = n/3;
    vector<vector<int>> d1(n+2,vector<int>(k+2,0));
    vector<vector<int>> d2(n+2,vector<int>(k+2,0));

    for(int i=n-2; i>=0; i--)
    {
        for(int j=1; j<=k; j++)
        {
            int a = slices[i] + d1[i+2][j-1];
            int b = 0 + d1[i+1][j];

            d1[i][j] = max(a,b);
        }
    }
    int a = d1[0][k];

    for(int i=n-1; i>=1; i--)
    {
        for(int j=1; j<=k; j++)
        {
            int a = slices[i] + d2[i+2][j-1];
            int b = 0 + d2[i+1][j];

            d2[i][j] = max(a,b);
        }
    }
    int b = d2[1][k];

    return max(a,b);
}

// Space Optimization - using three rows for each case
int maxSizeSlices(vector<int>& slices) 
{
    int n = slices.size();
    int k = n/3;
    vector<int> prev(k+2,0);
    vector<int> curr(k+2,0);
    vector<int> next(k+2,0);

    for(int i=n-2; i>=0; i--)
    {
        for(int j=1; j<=k; j++)
        {
            int a = slices[i] + next[j-1];
            int b = 0 + curr[j];

                prev[j] = max(a,b);
            }
            next = curr;
            curr = prev;
        }
        int a = prev[k];

        vector<int> prev2(k+2,0);
        vector<int> curr2(k+2,0);
        vector<int> next2(k+2,0);

        for(int i=n-1; i>=1; i--)
        {
            for(int j=1; j<=k; j++)
            {
                int a = slices[i] + next2[j-1];
                int b = 0 + curr2[j];

                prev2[j] = max(a,b);
            }
            next2 = curr2;
            curr2 = prev2;
        }
        int b = prev2[k];

        return max(a,b);
    }