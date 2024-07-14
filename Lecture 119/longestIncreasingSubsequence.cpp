// 300. Longest Increasing Subsequence
#include <bits/stdc++.h>
using namespace std;

// Recusrion
int solve(vector<int>& nums, int i, int l)
{
    if(i == nums.size())
        return 0;

    int a = solve(nums,i+1,l);
    int b = 0;
    if(nums[i]>l)
        b = solve(nums,i+1,nums[i]) + 1;

    return max(a,b);
}
int lengthOfLIS(vector<int>& nums) {
    return solve(nums,0,INT_MIN);
}

// Recusrion + Memorization
int solve(vector<int>& nums, int i, int l, vector<vector<int>> &dp)
{
    if(i == nums.size())
        return 0;

    if(dp[i][l+1] != -1)
        return dp[i][l+1];

    int a = solve(nums,i+1,l,dp);
    int b = 0;
    if(l==-1 || nums[i]>nums[l])
        b = solve(nums,i+1,i,dp) + 1;

    return dp[i][l+1] = max(a,b); //+1 beacuse we start l with -1.
}
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
    return solve(nums,0,-1,dp);
}

// Tabulation
int lengthOfLIS(vector<int>& nums) {
    int n = nums.size();
    vector<vector<int>> dp(n+1,vector<int> (n+1,0)); // initially all 0

    for(int i=n-1; i>=0; i--)
    {
        for(int l=i-1; l>=-1; l--)
        {
            int a = dp[i+1][l+1]; //l+1
            int b = 0;
            if(l==-1 || nums[i]>nums[l])
                b = dp[i+1][i+1] + 1; //i+1

            dp[i][l+1] = max(a,b);
        }
    }

    return dp[0][0];
}

// Space Optimization
int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    vector<int> curr(n+1,0);
    vector<int> prev(n+1,0);

    for(int i=n-1; i>=0; i--)
    {
        for(int l=i-1; l>=-1; l--)
        {
            int a = prev[l+1]; //l+1
            int b = 0;
            if(l==-1 || nums[i]>nums[l])
                b = prev[i+1] + 1; //i+1

            curr[l+1] = max(a,b);
        }
        prev = curr;
    }

    return prev[0];
}

// Most Optimal - TC:O(n*logn)
int lengthOfLIS(vector<int>& nums) 
{
    int n = nums.size();
    if(n == 0)
        return 0;

    vector<int> ans;
    ans.push_back(nums[0]);

    for(int i=1; i<n; i++)
    {
        if(nums[i]>ans.back())
            ans.push_back(nums[i]);
        else
        {
            int index = lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
            ans[index] = nums[i];
        }
    }

    return ans.size();
}