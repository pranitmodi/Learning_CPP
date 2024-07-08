#include <bits/stdc++.h>
using namespace std;

// Recursion
int solve(vector<int> &weight, vector<int> &value, int i, int w) 
{
	if(i<0)
		return 0;

	int incl = 0;

	if(w-weight[i] >= 0)
		incl = solve(weight,value,i-1,w-weight[i]) + value[i];

	int excl = solve(weight,value,i-1,w);
	return max(incl,excl);
}

// Recusrion + Memorization
int solve(vector<int> &weight, vector<int> &value, int i, int w, vector<vector<int>> &dp) 
{
	if(i<0)
		return 0;

	if(dp[i][w]!=-1)
		return dp[i][w]; 

	int incl = 0;

	if(w-weight[i] >= 0)
		incl = solve(weight,value,i-1,w-weight[i],dp) + value[i];

	int excl = solve(weight,value,i-1,w,dp);
	return dp[i][w] = max(incl,excl);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	vector<vector<int>> dp(n,vector<int>(maxWeight+1,-1));
	return solve(weight,value,n-1,maxWeight,dp);
}

// Tabulation
int solve3(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<vector<int>> dp(n,vector<int>(capacity+1,0));

    if(weight[0] <= capacity)
    {
        for(int i=weight[0]; i<=capacity; i++)
        {
            dp[0][i] = value[0];
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int incl = 0;
            if(weight[i] <= w)
            {
                incl = value[i] + dp[i-1][w-weight[i]];
            }
            int excl = dp[i-1][w];

            dp[i][w] = max(incl,excl);
        }
    }

    return dp[n-1][capacity];
}

// Space optimization - O(2*capacity)
int solve4(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<int> dp(capacity+1,0);
    vector<int> v(capacity+1,0);

    if(weight[0] <= capacity)
    {
        for(int i=weight[0]; i<=capacity; i++)
        {
            dp[i] = value[0];
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int w=0; w<=capacity; w++)
        {
            int incl = 0;
            if(weight[i] <= w)
            {
                incl = value[i] + dp[w-weight[i]];
            }
            int excl = dp[w];

            v[w] = max(incl,excl);
        }
        dp = v;
    }

    return dp[capacity];
}

// Space Optimization - O(capacity)
int solve4(vector<int> weight, vector<int> value, int n, int capacity)
{
    vector<int> dp(capacity+1,0);

    if(weight[0] <= capacity)
    {
        for(int i=weight[0]; i<=capacity; i++)
        {
            dp[i] = value[0];
        }
    }

    for(int i=1; i<n; i++)
    {
        for(int w=capacity; w>=0; w--)
        {
            int incl = 0;
            if(weight[i] <= w)
            {
                incl = value[i] + dp[w-weight[i]];
            }
            int excl = dp[w];

            dp[w] = max(incl,excl);
        }
    }

    return dp[capacity];
}