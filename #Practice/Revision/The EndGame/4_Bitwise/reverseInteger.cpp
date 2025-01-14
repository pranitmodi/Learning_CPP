// 7. Reverse Integer
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int reverse(int x) 
    {
        long ans = 0;
        while(x!=0)
        {
            int d = x%10;
            ans = (ans*10) + d;
            x = x/10;
        }    

        if(ans>INT_MAX || ans<INT_MIN)
            return 0;
        else
            return (int)ans;
    }
};