// 70 Climbing Stairs
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int climbStairs(int n) 
    {
        int a = 1;
        int b = 1;

        for(int i=2; i<=n; i++)
        {
            int c = b;
            b = a+b;
            a = c;
        }  

        return b;
    }
};