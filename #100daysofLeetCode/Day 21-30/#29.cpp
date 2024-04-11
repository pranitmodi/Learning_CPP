// 22. Generate Parentheses
#include <bits/stdc++.h>
using namespace std;
class Solution 
{
    public:
        void solve(vector<string> &ans, string s, int n, int l, int r)
        {
            if(l==n && r==n)
            {
                ans.push_back(s);
                return;
            }
            else if(l>n || r>n)
                return;

            if(l == r)
            {
                s.push_back('(');
                solve(ans,s,n,l+1,r);
            }
            else if(l>r)
            {
                s.push_back(')');
                solve(ans,s,n,l,r+1);
                s.pop_back();
                s.push_back('(');
                solve(ans,s,n,l+1,r);
            }
        }
        vector<string> generateParenthesis(int n) 
        {
            vector<string> ans;
            string s = "(";
            solve(ans,s,n,1,0);
            return ans;
        }
};