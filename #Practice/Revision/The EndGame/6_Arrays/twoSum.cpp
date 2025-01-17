// 1. Two Sum
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        map<int,int> m;

        m[nums[0]] = 0;
        for(int i=1; i<nums.size(); i++)
        {
            int search  = target - nums[i];
            if(m.find(search) != m.end())
                return {m[search], i};
            m[nums[i]] = i;
        }    
        return {};
    }
};