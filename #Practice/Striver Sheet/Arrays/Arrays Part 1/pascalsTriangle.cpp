// 118
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> generate(int numRows) 
    {
        vector<vector<int>> ans;
        vector<int> prev = {1};
        for(int i=1; i<=numRows; i++)
        {
            vector<int> v={1};
            ans.push_back(prev);
            for(int j=0; j<prev.size()-1; j++)
            {
                v.push_back(prev[j] + prev[j+1]);
            }
            v.push_back(1);
            prev = v;
        }

        return ans;
    }
};