// 26
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int removeDuplicates(vector<int>& nums) 
    {
        int w = 0;
        for(int i=0; i<nums.size();)
        {
            nums[w++] = nums[i]; 
            int j = i+1;
            while(j<nums.size() && nums[i]==nums[j])
            {
                j++;
            }
            i = j;
        }
        return w;
    }
};