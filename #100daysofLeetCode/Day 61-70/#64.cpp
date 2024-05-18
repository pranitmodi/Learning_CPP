// 1389. Create Target Array in the Given Order
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> createTargetArray(vector<int>& nums, vector<int>& index) 
    {
        vector<int> ans(nums.size(),-1);
        int m = -1;
        for(int i=0; i<index.size(); i++)
        {
            int l = index[i];
            if(ans[l] != -1)
            {
                for(int j=m; j>=l; j--)
                {
                    ans[j+1] = ans[j];
                }
                m = m+1;
            }
            ans[l] = nums[i];
            m = max(m,l);
        }

        return ans;
    }
};