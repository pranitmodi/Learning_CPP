// 389. Find the Difference
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    char findTheDifference(string s, string t) 
    {
        map<char,int> m;
        for(int i=0; i<t.length(); i++)
        {
            m[t[i]]++;
        }

        for(int i=0; i<s.length(); i++)
        {
            m[s[i]]--;
        }

        for(auto i:m)
        {
            if(i.second == 1)
                return i.first;
        }

        return NULL;
    }
};