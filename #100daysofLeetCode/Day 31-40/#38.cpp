// 557. Reverse Words in a String III
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
        s += " ";
        string w = "";
        string ans = "";
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == ' ' && w != "")
            {
                ans += w;
                if(i<s.length()-1)
                    ans += " ";
                w = "";
            }
            else
                w = s[i] + w;
        }
        return ans;
    }
};