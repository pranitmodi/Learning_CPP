// 88
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
    {
        int i=0;
        int j=0;

        if(n == 0)
            return;

        while(i<m)
        {
            while(i<m && nums1[i] <= nums2[j])
            {
                i++;
            }

            if(i == m)
                break;

            swap(nums1[i],nums2[j]);

            i++;

            int k = j;
            while(k<nums2.size()-1 && nums2[k] > nums2[k+1])
            {
                swap(nums2[k], nums2[k+1]);
                k++;
            }
        }

        while(i<nums1.size())
        {
            nums1[i++] = nums2[j++];
        }
    }
};