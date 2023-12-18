#include <bits/stdc++.h>
using namespace std;
void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) 
{
    if(n == 0)
        return;
    
    if(m == 0)
        nums1 = nums2;
        
    int i=0;
    int j=0;

    while(i<m)
    {
        if(nums1[i] <= nums2[j])
        {
            i++;
        }
        else
        {
            swap(nums1[i++],nums2[j]);
            sort(nums2.begin(),nums2.end());
        }
    }    

    while(i < (m+n))
    {
        swap(nums1[i++],nums2[j++]);
    }
}