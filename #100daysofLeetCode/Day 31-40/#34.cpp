// 455. Assign Cookies
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) 
    {
        sort(g.begin(),g.end());
        sort(s.begin(),s.end());
        
        int ans = 0;
        
        int j = 0;
        for(int i=0; i<g.size(); i++)
        {
            while(j<s.size() && s[j]<g[i])
                j++;
            if(j<s.size())
            {
                j++;
                ans++;
            }
            else
                break;
        }

        return ans;
    }
};