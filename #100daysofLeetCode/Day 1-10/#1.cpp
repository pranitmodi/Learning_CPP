// 6 Zigzag Conversion
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convert(string s, int numRows) 
    {
        vector<string> v(numRows,"");
        int i = 0;
        while(i<s.length())
        {
            for(int j=0; j<numRows && i<s.length(); j++)
            {
                v[j].push_back(s[i++]);
            }
            for(int j=numRows-2; j>0 && i<s.length(); j--)
            {
                v[j].push_back(s[i++]);
            }
        }    

        string ans = "";
        for(auto i:v)
        {
            ans += i;
        }

        return ans;
    }
};