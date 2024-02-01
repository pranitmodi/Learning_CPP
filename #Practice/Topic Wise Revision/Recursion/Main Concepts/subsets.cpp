#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int i, vector<int> &nums, vector<int> temp, vector<vector<int>>& ans)
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return;
        }

        solve(i+1,nums,temp,ans); // excluding the current element

        temp.push_back(nums[i]);
        solve(i+1,nums,temp,ans); // including the current element
    }
    vector<vector<int>> subsets(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        vector<int> temp;
        
        solve(0,nums,temp,ans);
        return ans;
    }
};