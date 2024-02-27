// 90
#include <bits/stdc++.h>
using namespace std;

// optimal approach
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &res, int i, vector<int> &nums)
    {
        if(i == nums.size())
        {
            ans.push_back(res);
            return;
        }

        res.push_back(nums[i]);
        solve(ans,res,i+1,nums);
        res.pop_back();

        while(i<nums.size()-1 && nums[i] == nums[i+1])
            i++;

        solve(ans,res,i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans,res,0,nums);
        return ans;
    }
};

// Passed
class Solution {
public:
    void solve(set<vector<int>> &st, vector<int> res, int i, vector<int> nums)
    {
        if(i == nums.size())
        {
            st.insert(res);
            return;
        }

        solve(st,res,i+1,nums);
        res.push_back(nums[i]);
        solve(st,res,i+1,nums);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        set<vector<int>> st;
        vector<int> res;
        solve(st,res,0,nums);
        vector<vector<int>> ans(st.begin(),st.end());
        return ans;
    }
};