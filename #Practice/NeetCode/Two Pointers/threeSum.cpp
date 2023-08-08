// LeetCode - 15
#include <bits/stdc++.h>
using namespace std;

// Approach - 1 TC = O(n^3)
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int w = 0; w<nums.size()-2; w++)
    {
        for(int i = w + 1; i<nums.size()-1; i++)
        {
            for(int j = i + 1; j<nums.size(); j++)
            {
                vector<int> temp;
                if(nums[i] + nums[j] + nums[w] == 0)
                {
                    int s = min(min(nums[i],nums[j]),nums[w]);
                    int l = max(max(nums[i],nums[j]),nums[w]);
                    temp.push_back(s);
                    temp.push_back((nums[i]+nums[j]+nums[w]) -  (s+l));
                    temp.push_back(l);
                    if(std::find(ans.begin(), ans.end(), temp) == ans.end())
                    {
                        ans.push_back(temp);
                    }
                }
            }
        }
    }
    return ans;
}


// Optimised Approach
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ans;
    sort(nums.begin(), nums.end());
    for(int w = 0; w<nums.size()-1; w++)
    {
        int i = w+1;
        int j = nums.size()-1;
        while(i<j)
        {
            if(nums[i] + nums[j] + nums[w] == 0)
            {
                ans.push_back({nums[w], nums[i], nums[j]});
                int c1 = nums[i];
                while(i<j && nums[i] == c1)
                    i++;
                
                c1 = nums[j];
                while(i<j && nums[j] == c1)
                    j--;
            }
            else if(nums[i] + nums[j] + nums[w] < 0)
                i++;
            else if(nums[i] + nums[j] + nums[w] > 0)
                j--;
        }
        while(w+1<nums.size() && nums[w] == nums[w+1])
            w++;
    }
    return ans;
}