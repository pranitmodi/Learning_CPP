// LeetCode - 217
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) 
    {
        // Approach 1 - Space Complexity more
        map<int,bool> check;
        for(int i=0; i<nums.size(); i++)
        {
            if (check.find(nums[i]) != check.end())
                return true;
            else
                check[nums[i]] = true;
        }    
        return false;

        // Approach 2 - More Optimized
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }
        return false;
    }
};