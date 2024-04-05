// 292. Nim Game
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool canWinNim(int n) 
    {
        if(n<=3)
            return true;

        // because minimum I have to pick one stone and opponent can maximum of 4 stones
        if(n%4 == 0)
            return false;
        else
            return true;
    }
};