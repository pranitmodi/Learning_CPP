// 540
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(vector<int>& nums, int i)
    {
        if(i == 0)
        {
            if(nums[0] != nums[1])
                return true;
        }
        else if(i == nums.size()-1)
        {
            if(nums[i] != nums[nums.size()-2])
                return true;
        }
        else
        {
            if(nums[i] != nums[i-1] && nums[i] != nums[i+1])
                return true;
        }

        return false;
    }

    int search(vector<int>& nums, int s, int e)
    {
        if(s>e)
        {
            return -1;
        }
        int mid = s + (e-s)/2;
        if(check(nums,mid))
            return nums[mid];
        else
        {
            int a = search(nums,s,mid-1);
            int b = search(nums,mid+1,e);

            if(a >= 0)
                return a;
            else
                return b;
        }
    }

    int singleNonDuplicate(vector<int>& nums) 
    {
        if(nums.size() == 1)
            return nums[0];
        return(search(nums,0,nums.size()-1));
    }
};