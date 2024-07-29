#include <bits/stdc++.h>
using namespace std;
int search(vector<int>& nums, int target) 
{
    int left = 0;
    int right = nums.size()-1;
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(target == nums[mid])
            return mid;
        else if(nums[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}
int main()
{

    return 0;
}