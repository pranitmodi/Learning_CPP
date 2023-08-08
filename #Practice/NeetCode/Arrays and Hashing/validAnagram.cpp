// LeetCode - 242
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;

        map<char,int> check;
        for(int i=0; i<s.length(); i++)
        {
            check[s[i]]++;
            check[t[i]]--;
        } 

        for(auto i:check)
        {
            if(i.second != 0)
                return false;
        }
        return true;
    }
};