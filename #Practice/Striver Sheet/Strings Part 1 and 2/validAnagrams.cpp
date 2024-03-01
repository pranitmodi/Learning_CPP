// 242
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) 
    {
        if(s.length() != t.length())
            return false;

        int arr[256] = {0};
        for(int i=0; i<s.length(); i++)
        {
            arr[s[i]]++;
            arr[t[i]]--;
        }

        for(int i=0; i<256; i++)
        {
            if(arr[i] != 0)
                return false;
        }
        return true;
    }
};