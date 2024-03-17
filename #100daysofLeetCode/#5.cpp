// 228 Summary Ranges
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) 
    {
        int i = 0;
        vector<string> ans;
        if(nums.size()==0)
            return ans;

        string str = to_string(nums[i++]);
        int curr = nums[0];
        int w = curr+1;
        while(i<nums.size())
        {
            while(i<nums.size() && nums[i] == curr+1)
                curr = nums[i++];

            if(curr != stoi(str))
            {
                str = str + "->" + to_string(curr);
                w = curr;
            }
            ans.push_back(str);

            if(i>=nums.size())
                break;
                
            str = to_string(nums[i]);
            curr = nums[i];
            i++;
        }
        
        if(w != curr)
            ans.push_back(str);
        return ans;
    }
};