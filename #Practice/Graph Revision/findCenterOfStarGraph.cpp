// 1791. Find Center of Star Graph
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findCenter(vector<vector<int>>& edges) 
    {
        int n = edges.size();
        vector<int> v(n+2,0);

        int ans = -1;
        int maxi = -1;
        for(int i=0; i<n; i++)
        {
            int a = edges[i][0];
            int b = edges[i][1];

            v[a]++;
            v[b]++;
        }

        for(int i=1;i<=(n+1);i++)
        {
            if(v[i] > maxi)
            {
                maxi = v[i];
                ans = i;
            }
        }

        return ans;
    }
};