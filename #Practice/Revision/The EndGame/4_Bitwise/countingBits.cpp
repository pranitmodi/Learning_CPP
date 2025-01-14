// 338. Counting Bits
#include <bits/stdc+.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> ans(n+1,0);
        for(int i=1; i<=n; i++)
        {
            int curr = ans[i>>1];
            ans[i] = (i&1) ? curr+1 : curr;
        }
        return ans;
    }
};