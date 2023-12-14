// 334
#include <bits/stdc++.h>
using namespace std;
bool increasingTriplet(vector<int>& nums) {

    int n = nums.size();
    
    // first will keep track of first element of triplet
    
    int first = INT_MAX;
    
    // second will keep track of second element of triple
    
    int second = INT_MAX;
    
    // second > first
    
    for(int i = 0; i < n; i++)
    {
        cout << first << " " << second << " " << nums[i] << endl;
        if(first >= nums[i])
        {
            first = nums[i];
        }
        else if(second >= nums[i])
        {
            second = nums[i];
        }
        else
            return true;
    }
    
    return false;
}
int main()
{
    vector<int> nums = {1,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,2,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,-1,-1,-1,-1,3};
    cout << increasingTriplet(nums) << endl;
}