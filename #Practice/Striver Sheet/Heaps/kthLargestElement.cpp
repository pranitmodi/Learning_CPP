// 215
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) 
    {
        priority_queue<int,vector<int>,greater<int>> minHeap;
        for(int i=0; i<nums.size(); i++)
        {
            if(i<k)
            {
                minHeap.push(nums[i]);
            }
            else
            {
                if(nums[i] >= minHeap.top())
                {
                    minHeap.pop();
                    minHeap.push(nums[i]);
                }
            }
        }    
        return minHeap.top();
    }
};