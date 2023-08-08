// LeetCode - 33
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int s = 0;
        int e = nums.size()-1;

        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] >= nums[0])
                s = mid + 1;
            else if(nums[mid] < nums[0])
                e = mid;
        }    
        cout << s << endl;

        if(nums[0] <= nums[e])
        {
            s = 0;
            e = nums.size()-1;
        }
        else if(target >= nums[0])
        {
            e = s - 1;
            s = 0;
        }
        else
            e = nums.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }
        return -1;
    }
};