#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void moveZeroes(vector<int>& nums) 
    {
        int i = 0;

        // Finding the first zero index, beaces after that all the elements have to be shifted
        while(nums[i] != 0)
        {
            i++;
            if(i >= nums.size())
                break;
        }

        // if no zero were there
        if(i >= nums.size())
            return;

        // now from that index, shifting all the non-zero elements
        int c = i;
        for(int j=i; j<nums.size(); j++)
        {
            if(nums[j] != 0)
            {
                nums[c++] = nums[j];
            }
        }

        // replacing the rest of the array with zero
        for(int j=c; j<nums.size(); j++)
        {
            nums[j] = 0;
        }
        
        return;
    }
};