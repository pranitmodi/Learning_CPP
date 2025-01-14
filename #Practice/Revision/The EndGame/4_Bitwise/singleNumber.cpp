// 136. Single Number
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int res = 0;
        for(int val:nums) {
            res = res ^ val;
        }
        return res;
    }
};