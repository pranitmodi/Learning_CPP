// 506. Relative Ranks
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) 
    {
        map<int,int> m;
        for(int i=0; i<score.size(); i++)
        {
            m[score[i]] = i;
        }    

        sort(score.begin(),score.end());
        vector<string> ans(score.size());

        int i = score.size()-1;

        if(i>=0)
        {
            ans[m[score[i]]] = "Gold Medal";
            i--;
            if(i>=0)
            {
                ans[m[score[i]]] = "Silver Medal";
                i--;
                if(i>=0)
                {
                    ans[m[score[i]]] = "Bronze Medal";
                }
                i--;
            }
        }

        int w = 4;
        while(i>=0)
        {
           ans[m[score[i]]] = to_string(w++);
           i--;
        }

        return ans;
    }
};