// 42
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int trap(vector<int>& height) 
    {
        int n = height.size();
        vector<int> left(n);
        vector<int> right(n);

        int bigR = 0;
        int bigL = 0;
        for(int i=0; i<n; i++)
        {
            left[i] = bigL;
            bigL = max(bigL, height[i]);
        }

        for(int i=n-1; i>=0; i--)
        {
            right[i] = bigR;
            bigR = max(bigR, height[i]);
        }

        int ans = 0;
        for(int i=0; i<n; i++)
        {
            int h = min(left[i],right[i]);
            if(h > height[i])
                ans += (h - height[i]);
        }

        return ans;
    }
};