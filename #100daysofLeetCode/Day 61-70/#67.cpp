// 1399. Count Largest Group
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countLargestGroup(int n) 
    {
        map<int,int> m;
        for(int i=1; i<=n; i++)
        {
            int w = i;
            int sum = 0;
            while(w>0)
            {
                sum += w%10;
                w = w/10;
            }
            m[sum]++;
        }    

        int ans = 0;
        int curr = 0;
        for(auto i:m)
        {
            if(i.second > curr)
            {
                curr = i.second;
                ans = 1;
            }
            else if(i.second == curr)
                ans++;
        }

        return ans;
    }
};