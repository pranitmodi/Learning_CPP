#include <bits/stdc++.h>
using namespace std;
int pivotIndex(vector<int>& nums)
{
    int sum = 0;
    int i;
    for(i=0; i<nums.size(); i++)
    {
        sum += nums[i];
    }    

    int cal = 0;
    for(i=0; i<nums.size(); i++)
    {
        sum -= nums[i];
        if(cal == sum)
            return i;

        cal += nums[i];
    }

    return -1;
}