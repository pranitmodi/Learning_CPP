// LeetCode - 34
#include <bits/stdc++.h>
using namespace std;
vector<int> searchRange(vector<int>& nums, int target) 
{
    vector<int> v = {-1,-1};

    // first occurence
    int s = 0;
    int e = nums.size()-1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            if(mid == 0 || nums[mid-1] < target)
            {
                v[0] = mid;
                break;
            }
            else
            {
                e = mid - 1;
            }
        }
        else if(nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }


    // last occurence
    s = 0;
    e = nums.size()-1;
    while(s <= e)
    {
        int mid = s + (e-s)/2;
        if(nums[mid] == target)
        {
            if(mid == nums.size()-1 || nums[mid+1] > target)
            {
                v[1] = mid;
                break;
            }
            else
            {
                s = mid + 1;
            }
        }
        else if(nums[mid] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }
    return v;
}