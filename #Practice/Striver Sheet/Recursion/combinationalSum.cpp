// 39 
#include <bits/stdc++.h>
using namespace std;

// my approach
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> res,int sum, int target, int i,vector<int> &candidates)
    {
        if(i == candidates.size())
        {
            if(sum == target)
                ans.push_back(res);
            return;
        }

        if(sum<=target)
            solve(ans,res,sum,target,i+1,candidates);

        if(target>=candidates[i])
        {
            for(int t=1; t<=(target/candidates[i]); t++)
            {
                res.push_back(candidates[i]);
                sum += candidates[i];
                if(sum<=target)
                    solve(ans,res,sum,target,i+1,candidates);
            }
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) 
    {
        vector<vector<int>> ans;
        vector<int> res;
        solve(ans,res,0,target,0,candidates);
        return ans;
    }
};