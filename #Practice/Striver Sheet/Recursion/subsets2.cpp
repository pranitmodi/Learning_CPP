// 90
#include <bits/stdc++.h>
using namespace std;

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