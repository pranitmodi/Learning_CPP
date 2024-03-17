// 209 Minimum Size Subarray Sum
// i dont there is need of any queue - can be improved
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) 
    {
        int ans = INT_MAX;
        int sum = 0;
        queue<int> qt;

        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] >= target)
                return 1;

            sum += nums[i];
            qt.push(i);

            if(sum >= target)
            {
                if(qt.size() < ans)
                    ans = qt.size();
                while(sum > target && qt.size()>1)
                {
                    sum = sum - nums[qt.front()];
                    qt.pop();
                    if(sum >= target && qt.size()<ans)
                        ans = qt.size();
                }
            }
        }    
        if(ans != INT_MAX)
            return ans;
        return 0;
    }
};