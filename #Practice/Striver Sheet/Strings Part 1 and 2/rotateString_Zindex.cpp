// 796
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        string str = "";
        for(int i=0; i<s.length(); i++)
        {
            str += s[i];
            string s2 = s.substr(i+1) + str;
            if(goal == s2)
                return true;
        }    

        return false;
    }
};