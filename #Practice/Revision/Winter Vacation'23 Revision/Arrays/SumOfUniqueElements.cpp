#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int sumOfUnique(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
            
        sort(nums.begin(),nums.end());
        int sum = 0;
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i-1] != nums[i])
                sum = sum + nums[i-1];
            else
            {
                int j = i;
                while(nums[j] == nums[i])
                    j++;
                
                i = j;
            }
        }    

        if(nums[nums.size()-1] != nums[nums.size()-2])
            sum = sum + nums[nums.size()-1];

        return sum;
    }
};