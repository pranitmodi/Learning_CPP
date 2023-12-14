// 345
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string reverseVowels(string s) 
    {
        vector<char> ch;
        for(int i=s.length()-1; i>=0; i--)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                ch.push_back(s[i]);
            }
        }    

        int c = 0;
        for(int i=0; i<s.length(); i++)
        {
            if(s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u' || s[i] == 'A' || s[i] == 'E' || s[i] == 'I' || s[i] == 'O' || s[i] == 'U')
            {
                s[i] = ch[c++];
            }
        }

        return s;
    }
};