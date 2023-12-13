// 1768
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string mergeAlternately(string word1, string word2) 
    {
        string w = "";
        for(int i=0; i<max(word1.length(),word2.length()); i++)
        {
            if((i+1)<=word1.length())
                w = w + word1[i];
            
            if((i+1)<=word2.length())
                w = w + word2[i];
        }
        return w;
    }
};