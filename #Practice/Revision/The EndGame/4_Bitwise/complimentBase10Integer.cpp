// 1009. Complement of Base 10 Integer
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int bitwiseComplement(int n) 
    {
        if(n == 0)
            return 1;
            
        int ans = 0;
        int count = 1;
        while(n>0)
        {
            if((n&1) == 0)
                ans += count;

            count = count*2;
            n = n>>1;
        }

        return ans;
    }
};