#include <bits/stdc++.h>
using namespace std;

// TLE
vector<int> maxSlidingWindow(vector<int>& nums, int k) 
{
    vector<int> ans(nums.size()-k+1);
    map<int,int> m;
    int maxi = nums[0];
    for(int i=0; i<k; i++)
    {
        m[nums[i]]++;
        if(nums[i] > maxi)
            maxi = nums[i];
    }
    int w = 0;
    ans[w++] = maxi;

    for(int i=1; i<=nums.size()-k; i++)
    {
        if(nums[i+k-1] == nums[i-1])
        {
            ans[w++] = maxi;
            continue;
        }
        m[nums[i-1]]--;
        if(m[maxi] == 0)
        {
            maxi = INT_MIN;
            m.erase(nums[i-1]);
        }

        m[nums[i+k-1]]++;
        
        map<int,int>::reverse_iterator it;
        for (it = m.rbegin(); it != m.rend(); it++)
        {
            if(it->first > maxi && it->second > 0)
            {
                maxi = it->first;
                break;
            }
        }
        
        if(m[maxi] > 0)
            ans[w++] = maxi;
    }
    return ans;
}