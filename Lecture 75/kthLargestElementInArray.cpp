// 215
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> q;
        int i = 0;
        while(i<nums.size())
        {
            if(i<k)
            {
                q.push(nums[i]);
            }
            else
            {
                if(nums[i] > q.top())
                {
                    q.pop();
                    q.push(nums[i]);
                }
            }
            i++;
        }
        return q.top();
    }
};