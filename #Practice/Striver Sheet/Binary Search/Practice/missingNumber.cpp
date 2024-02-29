// 268
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int missingNumber(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int s = 0;
        int e = nums.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(nums[mid] == mid)
                s = mid+1;
            else
                e = mid-1;
        }    

        return s;
    }
};