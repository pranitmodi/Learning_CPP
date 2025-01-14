// 191. Number of 1 Bits
// Hamming Distance
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int hammingWeight(int n) {
        int ans = 0;
        while(n>0)
        {
            if(n&1) ans++;
            n = n>>1;
        }
        return ans;
    }
};