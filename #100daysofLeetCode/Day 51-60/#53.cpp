// 303. Range Sum Query - Immutable
#include <bits/stdc++.h>
using namespace std;
class NumArray {
public:
    vector<int> v;
    NumArray(vector<int>& nums) {
        for(int i=0; i<nums.size(); i++)
            v.push_back(nums[i]);
    }
    
    int sumRange(int left, int right) 
    {
        int sum = 0;
        for(int i=left; i<=right; i++)
            sum += v[i];

        return sum;
    }
};