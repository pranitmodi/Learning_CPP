// 198. House Robber
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) 
    {
        int n = nums.size();
        vector<int> dp(n,0);
        dp[0] = nums[0];

        for(int i=1; i<n; i++)
        {
            if(i-2<0)
                dp[i] = max(dp[i-1],nums[i]);
            else
            {
                int incl = dp[i-2] + nums[i];
                int excl = dp[i-1];

                dp[i] = max(incl,excl);
            }
        }

        return dp[n-1];
    }
    int rob2(vector<int>& nums) 
    {
        int a = 0;
        int b = nums[0];

        for(int i=1; i<nums.size(); i++)
        {
            int incl = a + nums[i];
            a = b;
            b = max(incl,b);
        }

        return b;
    }
};