// 15
#include <bits/stdc++.h>
using namespace std;

// Optimal Solution, based on Two Sum
vector<vector<int>> threeSum(vector<int>& nums) 
{
    vector<vector<int>> ans;
    sort(nums.begin(),nums.end());
    for(int i=0; i<nums.size(); i++)
    {
        if(i>0 && nums[i] == nums[i-1]) // important to skip the same numbers for i
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

// Brute Force - TLE - O(n^3)
vector<vector<int>> threeSum(vector<int>& nums) 
{
    set<vector<int>> st;
    for(int i=0; i<nums.size(); i++)
    {
        for(int j=i+1; j<nums.size(); j++)
        {
            for(int k=j+1; k<nums.size(); k++)
            {
                if(nums[i] + nums[j] + nums[k] == 0)
                {
                    vector<int> temp = {nums[i],nums[k],nums[j]};
                    sort(temp.begin(),temp.end());
                    st.insert(temp);
                }
            }
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}

// Another Approach - TLE - O(n^2)
vector<vector<int>> threeSum(vector<int>& nums) 
{
    set<vector<int>> st;
    for(int i=0; i<nums.size(); i++)
    {
        map<int,bool> m; // or we can use this - set<int> m;
        for(int j=i+1; j<nums.size(); j++)
        {
            int k = 0 - (nums[i] + nums[j]);
            if(m.find(k) != m.end())
            {
                vector<int> temp = {nums[i],k,nums[j]};
                sort(temp.begin(),temp.end());
                st.insert(temp);
            }
            else
                m[nums[j]] = true; // m.insert(nums[j]);
        }
    }
    vector<vector<int>> ans(st.begin(),st.end());
    return ans;
}