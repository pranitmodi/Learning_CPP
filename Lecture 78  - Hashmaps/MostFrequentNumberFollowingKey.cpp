// 2190
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int mostFrequent(vector<int>& nums, int key) 
    {
        unordered_map<int, int> m;
        for (int i = 0; i < nums.size() - 1; i++) 
        {
            if (nums[i] == key)
                m[nums[i + 1]]++;
        }

        int sum = 0;
        int ans = 0;
        for (auto i : m) 
        {
            if (i.second > sum) 
            {
                ans = i.first;
                sum = i.second;
            }
        }
        return ans;
    }
};