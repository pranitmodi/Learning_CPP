// 77. Combinations
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<vector<int>> &ans, vector<int> &v, int i, int n, int k)
    {
        if(v.size() == k)
        {
            ans.push_back(v);
            return;
        }

        for(int j=i; j<=n; j++)
        {
            v.push_back(j);
            solve(ans,v,j+1,n,k);
            v.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) 
    {
        vector<vector<int>> ans;
        vector<int> v;
        solve(ans,v,1,n,k);
        return ans;
    }
};