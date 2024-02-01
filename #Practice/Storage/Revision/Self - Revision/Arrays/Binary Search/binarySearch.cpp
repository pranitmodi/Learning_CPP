// LeetCode - 704
#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) 
{
    int s = 0;
    int e = nums.size()-1;
    while(s <= e)
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