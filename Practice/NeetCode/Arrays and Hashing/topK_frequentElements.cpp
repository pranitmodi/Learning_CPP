// LeetCode - 347
#include <bits/stdc++.h>
using namespace std;

// Approach 1 - TC good, SC not so good but PASSED
vector<int> topKFrequent1(vector<int>& nums, int k) 
{
    // First Map to store all the frequency of the characters
    // Second map to store all the frequencies to the respective numbers

    map<int,vector<int>> m;
    map<int,int> w;
    vector<int> ans;

    for(int i=0; i<nums.size(); i++)
    {
        w[nums[i]]++;
    }

    for(auto i:w)
    {
        m[i.second].push_back(i.first);
    }

    map<int,vector<int>>::reverse_iterator it;
    for (it = m.rbegin(); it != m.rend(); it++)
    {
        for(auto j:(it->second))
        {
            ans.push_back(j);
            k--;
            if(k == 0)
                break;
        }
        if(k == 0)
            break;
    }

    return ans;
}

// Approach 2 - Passed and better than Approach 1
// Only one map is used
vector<int> topKFrequent(vector<int>& nums, int k) 
{
    // Used sorting and thus counted frequencies in O(n)
    // Directly stored in the second map
    sort(nums.begin(), nums.end());

    map<int,vector<int>> m;
    vector<int> ans;

    for(int i=0; i<nums.size();)
    {
        int c = 1;
        int j = i+1;
        while(j<nums.size() && nums[j] == nums[i])
        {
            c++;
            j++;
        }

        m[c].push_back(nums[i]);

        i = j;
    }

    map<int,vector<int>>::reverse_iterator it;
    for (it = m.rbegin(); it != m.rend(); it++)
    {
        for(auto j:(it->second))
        {
            ans.push_back(j);
            k--;
            if(k == 0)
                break;
        }
        if(k == 0)
            break;
    }

    return ans;
}
int main()
{
    vector<int> nums = {4,1,-1,2,-1,2,3};
    vector<int> v = topKFrequent(nums,2);
}