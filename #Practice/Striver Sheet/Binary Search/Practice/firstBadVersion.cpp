// 278
#include <bits/stdc++.h>
using namespace std;
bool isBadVersion(int m){}
class Solution {
public:
    int firstBadVersion(int n) 
    {
        int s = 1;
        int e = n;
        int ans = -1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;

            if(isBadVersion(mid))
            {
                ans = mid;
                e = mid-1;
            }
            else
                s = mid+1;
        }
        return ans;
    }
};