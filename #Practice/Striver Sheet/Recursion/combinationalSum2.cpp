// 90
#include <bits/stdc++.h>
using namespace std;

// my approach - 100% better
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &res,int sum, int &target, int i,vector<int> &candidates)
    {
        if(i >= candidates.size())
        {
            if(sum == target)
                ans.push_back(res);
            return;
        }

        sum += candidates[i];
        res.push_back(candidates[i]);
        if(sum <= target)
            solve(ans,res,sum,target,i+1,candidates);
        res.pop_back();
        sum -= candidates[i];

        while(i<candidates.size()-1 && candidates[i] == candidates[i+1])
            i++;
        if(sum <= target)
            solve(ans,res,sum,target,i+1,candidates);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) 
    {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>> ans;
        vector<int> res;
        int sum = 0;
        int i = 0;
        solve(ans,res,sum,target,i,candidates);
        return ans;
    }
};