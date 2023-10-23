#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void sortColors(vector<int>& nums) 
    {
        int n = nums.size();
        int i=0;
        int j = n-1;
        int c = 0;
        while(i<=j)
        {
            if(nums[i] == 2)
            {
                while(nums[j] == 2 && i<j)
                    j--;

                swap(nums[i],nums[j--]);
            }
            if(nums[i] == 0)
            {
                swap(nums[i],nums[c]);
                c++;
            }

            i++;
        }
    }
};