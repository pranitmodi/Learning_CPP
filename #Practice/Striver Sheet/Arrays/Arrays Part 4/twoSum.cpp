// 1
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) 
    {
        vector<int> res = nums;

        sort(res.begin(),res.end());
        int i=0;
        int j = res.size()-1;

        while(i<j)
        {
            if(res[i] + res[j] == target)
                break;
            else if(res[i] + res[j] > target)
                j--;
            else
                i++;
        }

        vector<int> ans = {-1,-1};
        for(int w=0; w<nums.size(); w++)
        {
            if(ans[0] == -1 && nums[w] == res[i])
                ans[0] = w;
            else if(ans[1] == -1 && nums[w] == res[j])
                ans[1] = w;
        }

        return ans;
    }
};