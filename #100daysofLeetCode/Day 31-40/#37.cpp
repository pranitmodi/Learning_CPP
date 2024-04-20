// 507 Perfect Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkPerfectNumber(int num) 
    {
        int ans = 0;
        for(int i=1; i<num; i++)
            if(num%i == 0)
                ans += i;
                
        return (ans == num);    
    }
};