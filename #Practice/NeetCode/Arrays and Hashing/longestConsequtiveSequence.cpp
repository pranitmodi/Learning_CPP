// LeetCode - 128
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(vector<int>& nums) 
{
    map<int,int> m;
    int ans = 0;

    // Since for sorting it would take O(n*logn), used map to automatically sort the integers
    for(int i=0; i<nums.size();i++)
    {
        m[nums[i]] = 1;
    }    

    for(auto i=m.begin(); i != m.end();)
    {
        int curr = i->first;
        int c = 1;
        i++;
        while(i->first == (curr+1) && i != m.end())
        {
            c++;
            curr = i->first;
            i++;
        }
        if(c > ans)
            ans = c;
    }
    return ans;
}
int main()
{
    vector<int> nums = {100,4,200,1,3,2};
    return longestConsecutive(nums);
}