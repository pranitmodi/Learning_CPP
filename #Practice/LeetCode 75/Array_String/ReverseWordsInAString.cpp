// 151
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseWords(string s) 
    {
        string w = "";
        string word = "";
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == ' ' && word != "")
            {
                w = w + word + " ";
                word = "";
            }
            else if(s[i] != ' ')
            {
                word = s[i] + word;
            }
        }

        if(word == "")
            return (w.substr(0,w.length()-1));
        return (w+word);
    }
};