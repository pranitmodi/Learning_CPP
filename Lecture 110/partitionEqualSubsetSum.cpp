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

        dp[i][tot] = (incl || excl);
        return (incl || excl);
    }
    bool canPartition(vector<int>& nums) {
        int sum = 0;
        for(int i:nums)
            sum += i;

        vector<vector<int>> dp(nums.size(),vector<int>(sum+1,-1));
        return solve(nums,sum,nums.size()-1,0,dp);
    }
};