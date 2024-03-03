// 128
#include <bits/stdc++.h>
using namespace std;
// For O(n) - store all the elements in a map, and then traverse the map

// O(n log n)
class Solution {
public:
    int longestConsecutive(vector<int>& nums) 
    {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int i=0;
        int cnt = 0;

        while(i<nums.size())
        {
            cnt = 1;
            while(i<nums.size()-1 && nums[i]+1 == nums[i+1])
            {
                i++;
                cnt++;

                while(i<nums.size()-1 && nums[i]==nums[i+1])
                    i++;
            }
            ans = max(ans,cnt);
            i++;
        }

        return ans;
    }
};