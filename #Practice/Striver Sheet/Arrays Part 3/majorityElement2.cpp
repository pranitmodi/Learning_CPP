// 229
#include <bits/stdc++.h>
using namespace std;

// Optimal Approach
// Intution - at max there can be two elements that appear more than n/3 times in an array.
// So, just focusing on the two elements only
// but at the end again check if they are the ones only
class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) 
    {
        int a = INT_MIN;
        int b = INT_MIN;
        int cn1 = 0;
        int cn2 = 0;

        for(int i=0; i<nums.size(); i++)
        {
            if(cn1 == 0 && nums[i] != b)
            {
                a = nums[i];
                cn1++;
            }
            else if(cn2 == 0 && nums[i] != a)
            {
                b = nums[i];
                cn2++;
            }
            else if(nums[i] == a)
                cn1++;
            else if(nums[i] == b)
                cn2++;
            else
            {
                cn1--;
                cn2--;
            }
        }

        cn1 = 0;
        cn2 = 0;
        for(int i=0; i<nums.size(); i++)
        {
            if(nums[i] == a)
                cn1++;
            
            if(nums[i] == b)
                cn2++;
        }

        vector<int> ans;
        if(cn1 > nums.size()/3)
            ans.push_back(a);

        if(cn2 > nums.size()/3)
            ans.push_back(b);

        return ans;
    }
};

// Approach 2 - O(n log n)
// sort(nums.begin(),nums.end());
// vector<int> ans;

// int n = nums.size()/3;
// int cnt = 1;
// int res = nums[0];
// for(int i=1; i<nums.size(); i++)
// {
//     if(res == nums[i])
//         cnt++;
//     else
//     {
//         if(cnt > n)
//             ans.push_back(res);

//         res = nums[i];
//         cnt = 1;
//     }
// }
// if(cnt > n)
//     ans.push_back(res);

// return ans;