// LeetCode - 912 - Sort an Array
// Try Quick Sort

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void merge(int s, int e, vector<int>& nums)
    {
        int mid = s + (e-s)/2;
        int l1 = mid - s + 1;
        int l2 = e - mid;

        int *a = new int[l1];
        int *b = new int[l2];

        int count = s;
        for(int i=0; i<l1; i++)
        {
            a[i] = nums[count++];
        }
        for(int i=0; i<l2; i++)
        {
            b[i] = nums[count++];
        }

        count = s;
        int c1 = 0;
        int c2 = 0;
        while(c1 < l1 && c2 < l2)
        {
            if(a[c1] < b[c2])
            {
                nums[count++] = a[c1++];
            }
            else
                nums[count++] = b[c2++];
        }

        while(c1 < l1)
        {
            nums[count++] = a[c1++];
        }

        while(c2 < l2)
        {
            nums[count++] = b[c2++];
        }

        delete []a;
        delete []b;

    }
    void mergeSort(int s, int e, vector<int>& nums)
    {
        if(s>=e)
            return;
        
        int mid = s + (e-s)/2;
        mergeSort(s,mid,nums);
        mergeSort(mid+1,e,nums);

        merge(s,e,nums);
    }
    vector<int> sortArray(vector<int>& nums) 
    {
        mergeSort(0,nums.size()-1,nums);
        return nums;
    }
};