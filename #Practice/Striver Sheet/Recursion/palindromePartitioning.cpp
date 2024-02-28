// 131
#include <bits/stdc++.h>
using namespace std;

// partitioning is the key, and we partition only when we find that the substring is palindrome.
class Solution {
public:
    // palindrome checker
    bool check(string s)
    {
        int i=0;
        int j = s.length()-1;

        while(i<j)
        {
            if(s[i] != s[j])
                return false;

            i++;
            j--;
        }

        return true;
    }
    void solve(vector<vector<string>> &ans, vector<string> res, int i, string s)
    {
        if(i == s.length())
        {
            ans.push_back(res);
            return;
        }

        string str = "";
        for(int j=i; j<s.length(); j++)
        {
            str.push_back(s[j]);
            if(check(str))
            {
                res.push_back(str);
                solve(ans,res,j+1,s);
                res.pop_back();
            }
        }
    }
    vector<vector<string>> partition(string s) 
    {
        vector<vector<string>> ans;
        vector<string> res;
        solve(ans,res,0,s);
        return ans;
    }
};