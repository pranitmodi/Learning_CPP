// 1417. Reformat The String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string solve(string s, int d, int l, string s1, string s2)
    {
        if(l>d)
            return solve(s,l,d,s2,s1);

        string w = "";
        int j = 0;
        while(w.length() < s.length())
        {
            w.push_back(s1[j]);
            if(w.length() < s.length())
                w.push_back(s2[j]);
            j++;
        }

        return w;
    }
    string reformat(string s) 
    {
        int digi = 0;
        int letter = 0;
        string sl = "";
        string sd = "";
        for(char i:s)  
        {
            if(i<='z' && i>='a')
            {
                digi++;
                sd += i;
            }
            else
            {
                letter++;
                sl += i;
            }
        }  

        if(abs(digi-letter) > 1)
            return "";
        
        string ans = solve(s,digi,letter,sd,sl);
        return ans;
    }
};