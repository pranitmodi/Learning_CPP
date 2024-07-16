// 1130. Minimum Cost Tree From Leaf Values
#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(int i, int j, vector<int>& arr,map<pair<int,int>,int> &maxi)
{
    if(i==j)
        return 0;

    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        ans = min(ans,(maxi[{i,k}]*maxi[{k+1,j}]) + solve(i,k,arr,maxi) + solve(k+1,j,arr,maxi));
    }
    return ans;
}
int mctFromLeafValues(vector<int>& arr) 
{
    map<pair<int,int>,int> maxi;
    for(int i=0; i<arr.size(); i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }
    return solve(0,arr.size()-1,arr,maxi);
}

// Recusrion + Tabulation
int solve(int i, int j, vector<int>& arr,map<pair<int,int>,int> &maxi,vector<vector<int>> &dp)
{
    if(i==j)
        return 0;

    if(dp[i][j]!=-1)
        return dp[i][j];

    int ans = INT_MAX;
    for(int k=i; k<j; k++)
    {
        ans = min(ans,(maxi[{i,k}]*maxi[{k+1,j}]) + solve(i,k,arr,maxi,dp) + solve(k+1,j,arr,maxi,dp));
    }
    return dp[i][j] = ans;
}
int mctFromLeafValues(vector<int>& arr) 
{
    map<pair<int,int>,int> maxi;
    for(int i=0; i<arr.size(); i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }
    vector<vector<int>> dp(arr.size()+1,vector<int>(arr.size()+1,-1));
    return solve(0,arr.size()-1,arr,maxi,dp);
}

// Tanulation
int mctFromLeafValues(vector<int>& arr) 
{
    map<pair<int,int>,int> maxi;
    for(int i=0; i<arr.size(); i++)
    {
        maxi[{i,i}] = arr[i];
        for(int j=i+1; j<arr.size(); j++)
        {
            maxi[{i,j}] = max(arr[j],maxi[{i,j-1}]);
        }
    }
    int n = arr.size();
    vector<vector<int>> dp(n, vector<int>(n, 0));

    // Fill the dp table using bottom-up approach
    for (int len = 2; len <= n; len++)  // length of subarray
    {
        for (int i = 0; i <= n - len; i++)
        {
            int j = i + len - 1;
            dp[i][j] = INT_MAX;
            for (int k = i; k < j; k++)
            {
                dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j] + maxi[{i, k}] * maxi[{k + 1, j}]);
            }
        }
    }
    return dp[0][n - 1];
}