// 275
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int m, vector<int>& citations)
    {
        int s = 0;
        int e = citations.size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(citations[mid] < m)
                s = mid+1;
            else
                e = mid-1;
        }

        int l = citations.size() - s;
        if(l >= m)
            return true;
        return false;
    }
    int hIndex(vector<int>& citations) 
    {
        int n = citations.size();
        int s = 0;
        int e = citations[n-1];

        int ans = -1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(check(mid,citations))
            {
                ans = mid;
                s = mid+1;
            }
            else
                e = mid-1;
        }

        return ans;
    }
};