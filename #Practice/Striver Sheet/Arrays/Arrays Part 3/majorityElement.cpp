// 169
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int majorityElement(vector<int>& nums) 
    {
        int res;
        int cnt = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(cnt == 0)
            {
                res = nums[i];
                cnt = 1;
            }
            else
            {
                if(nums[i] == res)
                    cnt++;
                else
                    cnt--;
            }
        }
        
        return res;
    }
};