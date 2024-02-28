// 540
#include <bits/stdc++.h>
using namespace std;

// using binary search, done in O(log n)
// number of elements in the left will be odd if single element present on the left of mid
class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) 
    {
        int n = nums.size();
        if(nums.size() == 1 || nums[0] != nums[1])
            return nums[0];

        if(nums[n-1] != nums[n-2])
            return nums[n-1];

        int s = 1;
        int e = nums.size()-2;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] != nums[mid+1] && nums[mid] != nums[mid-1])
                return nums[mid];
            else
            {
                if(nums[mid+1] == nums[mid])
                    mid++;

                if(mid&1)
                    s = mid + 1;
                else
                    e = mid - 1;
            }
        }    

        return nums[s];
    }
};