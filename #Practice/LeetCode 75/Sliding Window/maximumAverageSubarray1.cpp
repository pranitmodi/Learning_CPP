// 643
#include <bits/stdc++.h>
using namespace std;
double findMaxAverage(vector<int>& nums, int k) 
{
    int sum = 0;
    int i = 0;
    while(i<k)
    {
        sum += nums[i++];
    }

    double d = sum;
    i = 1;
    while(i<=(nums.size()-k))
    {
        sum = sum - nums[i-1] + nums[i+k-1];
        if(sum > d)
            d = sum;

        i++;
    }    

    return ((double)d/k);
}