// 18
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        sort(nums.begin(),nums.end());

        for(int i=0; i<nums.size(); i++)
        {
            for(int j=i+1; j<nums.size(); j++)
            {
                int k = j+1;
                int l = nums.size()-1;

                while(k<l)
                {
                    long int w = (long)nums[i] + (long)nums[j] + (long)nums[k] + (long)nums[l];
                    if(w == target)
                    {
                        vector<int> temp = {nums[i],nums[j],nums[k],nums[l]};
                        ans.push_back(temp);

                        int t = nums[k];
                        while(k<l && nums[k] == t)
                            k++;

                        t = nums[l];
                        while(k<l && nums[l] == t)
                            l--;
                    }
                    else if(w > target)
                        l--;
                    else
                        k++;
                }

                while(j<nums.size()-1 && nums[j+1] == nums[j])
                    j++;
            }
            while(i<nums.size()-1 && nums[i+1] == nums[i])
                i++;
        }
        return ans;
    }
};