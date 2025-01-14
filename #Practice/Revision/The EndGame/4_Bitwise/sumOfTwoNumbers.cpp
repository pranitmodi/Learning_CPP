// 371. Sum of Two Integers
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int getSum(int a, int b) 
    {
        if(b == 0)  return a;
        return getSum(a^b, (a&b)<<1);
    }
};