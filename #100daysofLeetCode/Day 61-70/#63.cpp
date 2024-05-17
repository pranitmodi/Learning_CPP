// 1365. How Many Numbers Are Smaller Than the Current Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) 
    {
        vector<int>v = nums;
        sort(v.begin(),v.end());
        map<int,int> m;

        for(int i=0; i<v.size(); i++)
        {
            if(m.find(v[i]) == m.end())
                m[v[i]] = i;
        }    

        for(int i=0; i<nums.size(); i++)
        {
            v[i] = m[nums[i]];
        }

        return v;
    }
};