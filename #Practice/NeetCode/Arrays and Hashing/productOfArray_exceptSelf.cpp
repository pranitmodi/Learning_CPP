// LeetCode - 238
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) 
    {
        // defining size while initialising array helps in Space Complexity
        vector<int> ans(nums.size());
        int p = 1;
        int c = 0;
        for(int i=0; i<nums.size(); i++)
        {   
            if(nums[i] != 0)
                p = p * nums[i];
            else
                c++;
        }

        int k = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0 && c == 1)
                ans[k++] = p;
            else if(nums[i] != 0 && c == 0)
                ans[k++] = (p/nums[i]);
            else
                ans[k++] = 0;
        }

        return ans;
    }
};