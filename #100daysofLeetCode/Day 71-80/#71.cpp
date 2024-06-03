// 386. Lexicographical Numbers
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(vector<int> &ans, int curr, int n)
    {
        if(curr > n)
            return;

        int t = curr*10;
        if(t != 0)
        {
            if(t<=n)
            {
                ans.push_back(t);
                solve(ans,t,n);
            }
        }

        for(int i=1; i<=9; i++)
        {
            int w = (curr*10)+i;
            if(w<=n)
            {
                ans.push_back(w);
                solve(ans,w,n);
            }
            else
                break;
        }
    }
    vector<int> lexicalOrder(int n)
    {
        vector<int> ans;
        if(n<1)    
            return ans;

        int curr = 0;
        solve(ans,curr,n);
        return ans;
    }
};