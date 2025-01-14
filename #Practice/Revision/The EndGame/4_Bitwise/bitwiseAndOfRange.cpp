// 201. Bitwise AND of Numbers Range
#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int rangeBitwiseAnd(int left, int right) 
    {
        while(left<right)
            right = right & (right-1);
        return right;     
    }
};