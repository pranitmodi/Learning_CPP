// 
#include <bits/stdc++.h>
using namespace std;

// Normal tabulation - TLE
int longestArithSeqLength(vector<int>& nums) 
{
    int n = nums.size();
    if(n<=2) return n;
    int ans = 0;

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            int res = 0;
            int d = nums[j]-nums[i];
            int w = i;
            for(int k=w-1; k>=0; k--)
            {
                if(nums[w]-nums[k] == d)
                {
                    res++;
                    w = k;
                }
            }
            ans = max(ans, 2 + res);
        }
    }    

    return ans;
}

// Recursion + Memorization - TLE
int solve(vector<int>& nums, int i, int d, unordered_map<int,int> dp[])
{
    if(i<0)
        return 0;

    if(dp[i].count(d))
        return dp[i][d];

    int res = 0;
    for(int k=i-1; k>=0; k--)
    {
        if(nums[i]-nums[k] == d)
            res = max(res,1+solve(nums,k,d,dp));
    }

    return dp[i][d] = res;
}
int longestArithSeqLength(vector<int>& nums) 
{
    int n = nums.size();
    if(n<=2) return n;
    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for(int i=0; i<n; i++)
    {
        for(int j=i+1; j<n; j++)
        {
            ans = max(ans,2 + solve(nums,i,nums[j]-nums[i],dp));
        }
    }    

    return ans;
}

// Tabulation
int longestArithSeqLength(vector<int>& nums) 
{
    int n = nums.size();
    if(n<=2) return n;
    int ans = 0;
    unordered_map<int,int> dp[n+1];

    for(int i=1; i<n; i++)
    {
        for(int j=0; j<i; j++)
        {
            int res = 1;
            int d = nums[i]-nums[j];
            if(dp[j].count(d))
                res = dp[j][d];

            dp[i][d] = 1 + res;
            ans = max(ans, dp[i][d]);
        }
    }    

    return ans;
}