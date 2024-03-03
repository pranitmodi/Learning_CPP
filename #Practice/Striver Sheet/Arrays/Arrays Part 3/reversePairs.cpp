// 493
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int merge(vector<int> &nums, int s, int e, int mid)
    {
        int cnt = 0;
        vector<int> temp;
        int i = s;
        int j = mid+1;

        while(i<=mid)
        {
            if(j<=e && ((int)ceil(nums[i]/2.0)) > nums[j])
            {
                cnt += (mid-i+1);
                j++;
            }
            else
                i++;
        }

        i = s;
        j = mid+1;

        while(i<=mid && j<=e)
        {
            if(nums[i] <= nums[j])
                temp.push_back(nums[i++]);
            else
                temp.push_back(nums[j++]);
        }

        while(i<=mid)
            temp.push_back(nums[i++]);

        while(j<=e)
            temp.push_back(nums[j++]);

        i = 0;
        for(int j=s; j<=e; j++)
            nums[j] = temp[i++];

        return cnt;
    }
    int mergeSort(vector<int> &nums, int s, int e)
    {
        if(s>=e)
            return 0;

        int mid = s + (e-s)/2;
        int ch = 0;
        ch += mergeSort(nums,s,mid);
        ch += mergeSort(nums,mid+1,e);

        ch += merge(nums,s,e,mid);
        return ch;
    }
    int reversePairs(vector<int>& nums) 
    {
        return mergeSort(nums,0,nums.size()-1);
    }
};