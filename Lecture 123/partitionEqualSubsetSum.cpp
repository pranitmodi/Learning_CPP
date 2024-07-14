// 416. Partition Equal Subset Sum
#include <bits/stdc++.h>
using namespace std;

// Recursion + Memorization
class Solution {
public:
    // have a sum of all the elements present, now afer each subset,
    // the sum of the subset = (total - sum)
    // return true
    bool solve(vector<int> &nums, int sum, int i, int tot, vector<vector<int>> &dp)
    {
        if(i<0)
        {
            if((sum-tot) == tot)
                return true;
            else
                return false;
        }

        if(dp[i][tot] != -1)
            return dp[i][tot];

        bool incl = solve(nums,sum,i-1,tot+nums[i],dp);
        bool excl = solve(nums,sum,i-1,tot,dp);

        return dp[i][tot] = (incl || excl);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)
            sum += i;

        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return solve(nums,sum,nums.size()-1,0,dp);
    }
};

// Tabulation
bool canPartition(vector<int>& nums) 
{
    int sum = 0;
    for(int i:nums)
        sum += i;

    if (sum & 1) // if sum is odd then return false
        return false;

    // total = sum
    int n = nums.size();
    vector<vector<int>> dp(nums.size()+1,vector<int>(sum+1,0));
    for(int i=0; i<=n; i++)  
        dp[i][0] = 1;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=sum/2; j++)
        {
            bool incl = false;
            if(j-nums[i]>=0)
                incl = dp[i+1][j-nums[i]];
            bool excl = dp[i+1][j];

            dp[i][j] = (incl || excl);
        }
    }

    return dp[0][sum/2];
}

// Space Optimization
bool canPartition(vector<int>& nums) 
{
    int sum = 0;
    for(int i:nums)
        sum += i;

    if(sum & 1)
        return false;

    int n = nums.size();
    vector<int> curr(sum/2 +1,0);
    vector<int> prev(sum/2 +1,0);

    curr[0] = 1;
    prev[0] = 1;

    for(int i=n-1; i>=0; i--)
    {
        for(int j=0; j<=sum/2; j++)
        {
            bool incl = false;
            if(j-nums[i]>=0)
                incl = prev[j-nums[i]];
            bool excl = prev[j];

            curr[j] = (incl || excl);
        }
        prev = curr;
    }

    return prev[sum/2];
}