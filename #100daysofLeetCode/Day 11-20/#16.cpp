// 190. Reverse Bits
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    uint32_t reverseBits(uint32_t n) 
    {
        uint32_t ans = 0;
        for(int i=0; i<32; i++)
        {
            ans = ans<<1;
            ans = ans | (n&1);
            n = n>>1;
        }
        return ans;
    }
};