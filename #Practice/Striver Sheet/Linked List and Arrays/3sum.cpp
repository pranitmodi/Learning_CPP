// 15
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) 
    {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());
        for(int i=0; i<nums.size(); i++)
        {
            if(i>0 && nums[i] == nums[i-1])
                continue;
            int j=i+1; 
            int k=nums.size()-1;
            while(j<k)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i],nums[k],nums[j]};
                    sort(temp.begin(),temp.end());
                    ans.push_back(temp);

                    int t = nums[j];
                    while(j<k && nums[j] == t)
                        j++;

                    t = nums[k];
                    while(j<k && nums[k] == t)
                        k--;
                }
                else if(nums[i] + nums[j] + nums[k] > 0)
                    k--;
                else
                    j++;
            }
        }
        return ans;
    }
};