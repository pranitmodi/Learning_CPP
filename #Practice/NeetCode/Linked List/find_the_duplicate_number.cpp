// leetCode - 287
#include <bits/stdc++.h>
using namespace std;
int findDuplicate(vector<int>& nums) 
{
    vector<int> v(nums.size()-1,0);

    for(int i=0; i<nums.size(); i++)
    {
        if(v[nums[i] - 1] == 1)
            return nums[i];
        
        v[nums[i] - 1] = 1;
    }
    return -1;
}