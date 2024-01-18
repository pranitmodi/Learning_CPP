// Did not use Trie
// 14
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        int l = strs.size();
        if(l == 0)
            return "";

        sort(strs.begin(),strs.end());
        string s1 = strs[0];

        for(int i=1; i<strs.size(); i++)
        {
            string w = "";
            for(int j=0; j<s1.length(); j++)
            {
                if(s1[j] == strs[i][j])
                    w += s1[j]; 
                else
                    break;
            }
            s1 = w;
        }
        
        return s1;
    }   
};