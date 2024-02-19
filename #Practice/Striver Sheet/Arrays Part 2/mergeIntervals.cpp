// 56
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) 
    {
        vector<vector<int>> ans;
        sort(intervals.begin(),intervals.end());
        for(int i=0; i<intervals.size()-1; i++)
        {
            int u1 = intervals[i][0];
            int v1 = intervals[i][1];

            int u2 = intervals[i+1][0];
            int v2 = intervals[i+1][1];

            if(v1>=u2 && v2>=u1)
            {
                intervals[i+1][0] = u1;
                intervals[i+1][1] = max(v1,v2);

                intervals[i][0] = -1;
                intervals[i][1] = -1;
            }
        }    

        for(int i=0; i<intervals.size(); i++)
        {
            int u1 = intervals[i][0];
            int v1 = intervals[i][1];

            if(u1 != -1 && v1 != -1)
            {
                ans.push_back(intervals[i]);
            }
        }

        return ans;
    }
};