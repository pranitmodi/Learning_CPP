// 434. Number of Segments in a String
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int countSegments(string s) 
    {
        s = s + " ";
        int ans = 0;
        for(int i=1; i<s.length(); i++)
        {
            if(s[i] == ' ' && s[i-1] != ' ')
                ans++;
        }
        return ans;    
    }
};