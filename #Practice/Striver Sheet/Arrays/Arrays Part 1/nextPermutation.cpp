// 31
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void nextPermutation(vector<int>& nums) 
    {
        // in built function
        // next_permutation(nums.begin(),nums.end());

        // finding the break point
        int p = -1;
        for(int i=nums.size()-2; i>=0; i--)
        {
            if(nums[i] < nums[i+1])
            {
                p = i;
                break;
            }
        }

        // if no break point, then array is in descreasing order
        // thus next permutation will be array in increasing order
        if(p == -1)
        {
            reverse(nums.begin(),nums.end());
            return;
        }


        // now swapping the breaking point element with the first bigger element from the back
        for(int i=nums.size()-1; i>p; i--)
        {
            if(nums[i] > nums[p])
            {
                swap(nums[i],nums[p]);
                break;
            }
        }

        // now reversing all the rest of the elements
        reverse(nums.begin()+p+1,nums.end());
    }
};