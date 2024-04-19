// 541. Reverse String II
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseStr(string s, int k) 
    {
        string ans = "";
        int i = k-1;
        int f = -1;
        while(i<s.length())
        {
            f = i;
            for(int j=1; j<=k; j++)
                ans.push_back(s[f--]);

            f = i;
            for(int j=1; j<=k; j++)
            {
                if(i+j < s.length())
                {
                    ans.push_back(s[i+j]);
                    f = i+j;
                }
            }
            i += 2*k;
        }    

        int w = s.length()-1;
        while(w>f)
            ans.push_back(s[w--]);

        return ans;
    }
};