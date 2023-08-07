//LeetCode - 153
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) 
    {
        int s = 0;
        int e = nums.size()-1;

        if(nums[s] < nums[e])
            return nums[s];

        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid+1] < nums[mid])
                return nums[mid+1];
            if(nums[mid] < nums[mid-1])
                return nums[mid];
            if(nums[mid] > nums[e])
                s = mid + 1;
            else if(nums[mid] < nums[e])
                e = mid - 1;
        }
        return nums[s];
    }
};