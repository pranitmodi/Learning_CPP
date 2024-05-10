// 896. Monotonic Array
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isMonotonic(vector<int>& nums) 
    {
        if(nums.size()<=1)
            return true;

        int c = (nums[0]<nums[nums.size()-1]) ? 0 : 1;
        
        for(int i=0; i<nums.size()-1; i++)
        {
            if(c == 0)
            {
                if(nums[i]>nums[i+1])
                    return false;
            }
            else 
            {
                if(nums[i]<nums[i+1])
                    return false;
            }
        }

        return true;
    }
};