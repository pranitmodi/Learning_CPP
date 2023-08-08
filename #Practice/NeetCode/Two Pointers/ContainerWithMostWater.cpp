// LeetCode - 11
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) 
    {
        // Approach 1- O(n^2)
        // int ans = 0;
        // for(int i=0; i<height.size(); i++)
        // {
        //     for(int j=i+1; j<height.size(); j++)
        //     {
        //         int a = j-i;
        //         int b = min(height[i],height[j]);

        //         if((a*b) > ans)
        //             ans = a*b;
        //     }
        // }
        // return ans;

        // Approach 2
        int i = 0;
        int j = height.size()-1;
        int ans = 0;
        while(j>i)
        {
            // always calculate area from the smaller height
            ans = max(ans,(min(height[i],height[j]) * abs(i-j)));
            // because if the size is already big then no point in shifting that index, the smaller one should be shifted in order to get to a bigger height thus bigger area
            if(height[i] < height[j])
                i++;
            else
                j--;
        }
        return ans;
    }
};