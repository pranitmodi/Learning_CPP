// 217. Contains Duplicate
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size()-1; i++)
        {
            if(nums[i] == nums[i+1])
                return true;
        }

        return false;
    }
};