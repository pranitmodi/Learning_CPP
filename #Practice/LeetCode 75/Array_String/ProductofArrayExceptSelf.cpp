// 238
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int sum = 1;
        int n = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == 0)
                n++;
            else
                sum = sum * nums[i];
        }

        for(int i=0; i<nums.size(); i++)
        {
            if(n == 0)
                nums[i] = sum / nums[i];
            else if(nums[i] == 0 && n == 1)
                nums[i] = sum;
            else
                nums[i] = 0;
        }

        return nums;
    }
};