#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) 
    {
        int low = 0;
        int high = nums.size()-1;

        while(low < high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] >= nums[0])
                low = mid + 1;
            else
                high = mid;
        }
        
        int pivot = low;
        cout << pivot << " " << nums[pivot] << endl;
        if(nums[nums.size()-1] >= nums[0])
        {
            high = nums.size()-1;
            low = 0;
        }
        else if(target >= nums[0])
        {
            low = 0;
            high = pivot - 1;
        }
        else
        {
            low = pivot;
            high = nums.size()-1;
        }

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if(nums[mid] == target)
                return mid;
            else if(nums[mid] > target)
                high = mid - 1;
            else
                low = mid + 1;
        }

        return -1;
    }
};