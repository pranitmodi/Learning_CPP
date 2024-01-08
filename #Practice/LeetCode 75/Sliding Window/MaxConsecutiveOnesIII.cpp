// 1004
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) 
    {
        int n= nums.size();
        int i=0, j=0, maxLength=0;
        int countZero=0;
        while(j < n)
        {
            if(nums[j]==0)
                countZero++;

            while(countZero>k)
            {
                if(nums[i]==0)
                    countZero--;
                i++;
            }
            maxLength = max(maxLength, j-i+1);
            j++;
        }
        return maxLength;     
    }
};