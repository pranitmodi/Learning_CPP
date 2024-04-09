// 57. Insert Interval
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals,vector<int>& newInterval) 
    {
        if(newInterval.size() == 0)
            return intervals;
        if(intervals.size() == 0)
        {
            intervals.push_back(newInterval);
            return intervals;
        }

        vector<vector<int>> ans;
        int i = 0;
        int c = 0;
        if(intervals[0][0] > newInterval[1])
        {
            ans.push_back(newInterval);
            c = 1;
        }
        while(i < intervals.size()) 
        {
            if(intervals[i][1] >= newInterval[0] && c == 0) 
            {
                if(intervals[i][0] > newInterval[1])
                {
                    ans.push_back(newInterval);
                    ans.push_back(intervals[i]);
                    c = 1;
                    i++;
                    continue;
                }
                c = 1;
                int start = min(intervals[i][0], newInterval[0]);
                int end = -1;
                if(newInterval[1]>intervals[i][1])
                {
                    while(i<intervals.size() && intervals[i][0]<=newInterval[1])
                        i++;
                    i--;
                    end = max(intervals[i][1],newInterval[1]);
                }
                else
                    end = intervals[i][1];

                ans.push_back({start,end});
            }
            else
                ans.push_back(intervals[i]);

            i++;
        }
        if(c == 0)
            ans.push_back(newInterval);

        return ans;
    }
};