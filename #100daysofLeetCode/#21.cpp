// 414. Third Maximum Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int thirdMax(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());

        if(nums.size()<=2)
            return(nums[nums.size()-1]);

        int k = 2;
        for(int i=nums.size()-1; i>0; i--)
        {
            if(k == 0)
                return nums[i];
            if(nums[i] != nums[i-1])
                k--;
        }
        
        if(k == 0)
            return nums[0];
        else
            return nums[nums.size()-1];
    }
};