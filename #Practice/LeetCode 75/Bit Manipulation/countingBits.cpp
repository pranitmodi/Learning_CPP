#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> v(n+1);
        for(int i=0; i<=n; i++)
        {
            int n = i;
            int c = 0;
            while(n != 0)
            {
                if(n&1)
                    c++;
                
                n = n>>1;
            }

            v[i] = c;
        }

        return v;
    }
};