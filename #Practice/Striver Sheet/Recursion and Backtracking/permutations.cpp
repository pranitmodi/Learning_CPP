// 46
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &nums, int i)
    {
        if(i == nums.size())
        {
            ans.push_back(nums);
            return;
        }

        for(int w=i; w<nums.size(); w++)
        {
            swap(nums[w],nums[i]);
            solve(ans,nums,i+1);
            swap(nums[w],nums[i]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        solve(ans,nums,0);
        return ans;
    }
};