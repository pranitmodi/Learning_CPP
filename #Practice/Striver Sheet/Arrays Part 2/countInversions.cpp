#include <bits/stdc++.h>
using namespace std;
class Solution{
  public:
    long long int merge(long long arr[], long long start, long long end)
    {
        long long int cnt = 0;
        long long mid = start + (end-start)/2;
        vector<int> temp;
        int left = start;
        int right = mid+1;
        while(left<=mid && right<=end)
        {
            if(arr[left] <= arr[right])
            {
                temp.push_back(arr[left++]);
            }
            else
            {
                temp.push_back(arr[right++]);
                cnt += (mid-left+1); // if left sorted array element is bigger than the right element.
            }
        }
        while(left<=mid)
            temp.push_back(arr[left++]);

        while(right<=end)
            temp.push_back(arr[right++]);

        int j = 0;
        for(int i=start; i<=end; i++)
        {
            arr[i] = temp[j++];
        }

        return cnt;
    }
    long long int mergeSort(long long arr[], long long start, long long end)
    {
        long long int cnt = 0;
        if(start >= end)
            return cnt;

        long long mid = start + (end-start)/2;
        cnt += mergeSort(arr,start,mid);
        cnt += mergeSort(arr,mid+1,end);

        cnt += merge(arr,start,end);

        return cnt;
    }
    long long int inversionCount(long long arr[], long long N)
    {
        return mergeSort(arr,0,N-1);
    }

};
