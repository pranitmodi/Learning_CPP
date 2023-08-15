// leetCode - 567
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool checkEqual(int ch[], int ch1[])
    {
        for(int i=0; i<26; i++)
        {
            if(ch[i]!=ch1[i])
                return false;
        }
        return true;
    }
    bool checkInclusion(string s1, string s2) 
    {
        if(s1.size() > s2.size())
            return false;

        // frequency of character of s1
        int ch[26] = {0};
        for(int i=0; i<s1.size(); i++)
        {
            int index = s1[i] - 'a';
            ch[index]++;
        }

        // finding first window
        string str = s2.substr(0,s1.size());
        int ch1[26] = {0};

        // frequency of character of first window of s2
        for(int j=0; j<str.size(); j++)
        {
            int index = str[j] - 'a';
            ch1[index]++;
        }

        // checking for the first window
        if(checkEqual(ch, ch1))
        {
            return true;
        }

        for(int i=1; i<=(s2.size()-s1.size()); i++)
        {
            str = s2.substr(i,s1.size());

            // removing the first element of previous window
            int index = s2[i-1] - 'a';
            ch1[index]--;

            // adding the new element added in the window
            int ele = i + s1.size() - 1;
            index = s2[ele] - 'a';
            ch1[index]++;

            // checking
            if(checkEqual(ch, ch1))
            {
                return true;
            }
        }

        return false;
    }
};