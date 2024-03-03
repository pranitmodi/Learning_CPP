// gfg
#include <bits/stdc++.h>
using namespace std;
class Solution{
    public:
    int maxLen(vector<int>&A, int n)
    {   
        map<int,int> m;
        int sum = 0;
        int res = 0;
        for(int i=0; i<A.size(); i++)
        {
            sum += A[i];
            if(sum == 0)
                res = i+1;
            else if(m.find(sum) != m.end())
            {
                int w = m[sum];
                res = max(res,(i-w));
            }
            else
                m[sum] = i;
        }
        return res;
    }
};