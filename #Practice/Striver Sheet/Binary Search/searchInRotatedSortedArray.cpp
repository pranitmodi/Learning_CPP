#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        if(nums.size() == 1)
            if(nums[0] == target) return 0;
        int s = 0;
        int e = nums.size()-1;
        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;

            if(nums[mid] >= nums[0])
                s = mid +1;
            else 
                e = mid;
        }   

        int pivot = s;

        if(nums[0] <= nums[nums.size()-1])
        {
            s = 0;
            e = nums.size()-1;
        }
        else if(target >= nums[0])
        {
            s = 0;
            e = pivot-1;
        }
        else
        {
            s = pivot;
            e = nums.size()-1;
        }

        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                e = mid -1;
            else
                s = mid +1;
        }

        return -1;
    }
};