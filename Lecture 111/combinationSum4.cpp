// 377. Combination Sum IV
#include <bits/stdc++.h>
using namespace std;

// Recusrion 
void solve(vector<int>& nums, int target, int &ans)
{
    if(target < 0)
        return;

    if(target == 0)
    {
        ans++;
        return;
    }

    for(int i=0; i<nums.size(); i++)
    {
        solve(nums,target-nums[i],ans);
    }
}
int combinationSum4(vector<int>& nums, int target) {
    int ans = 0;
    solve(nums,target,ans);
    return ans;
}

// Recursion + Memorization
int solve2(vector<int>& nums, int target, vector<int> &dp)
{
    if(target < 0)
        return 0;

    if(target == 0)
    {
        return 1;
    }

    if(dp[target] != -1)
    {
        return dp[target];
    }

    int ans = 0;
    for(int i=0; i<nums.size(); i++)
    {
        ans += solve2(nums,target-nums[i],dp);
    }

    return dp[target] = ans;
}
int combinationSum4(vector<int>& nums, int target) 
{
    vector<int> dp(target+1,-1);
    return solve2(nums,target,dp);
}

// Tabulation
int solveTab(vector<int>& nums, int target) 
{
    vector<int> dp(target+1,-1);
    dp[0] = 1;
    for(int i=1; i<=target; i++)
    {
        long int ans = 0;
        for(int j=0; j<nums.size(); j++)
        {
            if(i-nums[j] >= 0)
                ans += dp[i-nums[j]];
        }
        dp[i] = ans;
    }

    return dp[target];
}
