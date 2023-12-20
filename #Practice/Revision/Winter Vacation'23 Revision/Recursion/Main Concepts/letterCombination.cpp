#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void solve(int i, string digits, string w,vector<string> &ans,string mapping[])
    {
        if(i>=digits.length())
        {
            ans.push_back(w);
            return;
        }

        char ch = digits[i];
        int d = (int)(ch-'0');

        string str = mapping[d];
        for(int j=0; j<str.length(); j++)
        {
            w.push_back(str[j]);
            solve(i+1,digits,w,ans,mapping);
            w.pop_back();
        }
    }
    vector<string> letterCombinations(string digits) 
    {
        vector<string> ans;
        if(digits == "")
            return ans;

        string mapping[10] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        string w="";

        int i=0;
        solve(i,digits,w,ans,mapping);
        return ans;
    }   
};