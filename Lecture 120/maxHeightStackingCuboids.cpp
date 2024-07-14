// 1691. Maximum Height by Stacking Cuboids 
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int> &a, vector<int> &b)
    {
        if(a[0]>=b[0] && a[1]>=b[1] && a[2]>=b[2])
            return true;
        return false;
    }
    int solve(vector<vector<int>>& cuboids)
    {
        int n = cuboids.size();
        vector<int> curr(n+1,0);
        vector<int> prev(n+1,0);

        for(int i=n-1; i>=0; i--)
        {
            for(int l=i-1; l>=-1; l--)
            {
                int a = prev[l+1];
                int b = 0;
                if(l==-1 || check(cuboids[i],cuboids[l]))
                    b = prev[i+1] + cuboids[i][2]; //adding height

                curr[l+1] = max(a,b);
            }
            prev = curr;
        }

        return prev[0];
    }
    int maxHeight(vector<vector<int>>& cuboids) 
    {
        for(auto &a:cuboids)
            sort(a.begin(),a.end());

        sort(cuboids.begin(),cuboids.end());

        return solve(cuboids);
    }   
};