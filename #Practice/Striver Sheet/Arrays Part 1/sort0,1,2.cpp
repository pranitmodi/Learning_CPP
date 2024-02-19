// 75
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int i = 0;
        int j = nums.size()-1;
        int k = i;
        while(k<=j)
        {
            if(nums[k] == 0)
            {
                swap(nums[i],nums[k]);
                i++;
                k++;
            }
            else if(nums[k] == 2)
            {
                swap(nums[j],nums[k]);
                j--;
            }
            else
                k++;
        }    
    }
};