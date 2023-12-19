// 724
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int pivotIndex(vector<int>& nums) 
    {
        int sum = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum = sum + nums[i];
        }    

        int s = 0;
        for(int i=0; i<nums.size(); i++)
        {
            sum = sum - nums[i];
            if(s == sum)
                return i;
            
            s = s + nums[i];
        }

        return -1;
    }
};