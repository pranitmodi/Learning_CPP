// LeetCode - 1011
// Capacity To Ship Packages Within D Days
// A conveyor belt has packages that must be shipped from one port to another within days days.
// The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
// Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.

#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isPossible(vector<int>& weights, int days, int mid)
    {
        int c = 0;
        int sum = 0;
        for(int i=0; i<weights.size(); i++)
        {
            if(sum + weights[i] <= mid)
                sum = sum + weights[i];
            else
            {
                c++;
                if(c>days || weights[i] > mid || c == days)
                    return false;
                
                sum = weights[i];
            }
        }
        return true;
    }
    int shipWithinDays(vector<int>& weights, int days) 
    {
        int sum = 0;
        for(int i=0; i<weights.size(); i++)
        {
            sum = sum + weights[i];
        }

        int s = 0;
        int e = sum;
        int ans;
        while(s<=e)
        {
            cout << "s: " << s << " " << "e: " << e << endl;
            int mid = s + (e-s)/2;
            cout << "mid: " << mid << endl;
            if(isPossible(weights,days,mid))
            {
                ans = mid;
                e = mid - 1;
            }
            else
                s = mid + 1;
        }
        return ans;
    }
};