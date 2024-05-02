// 2423. Remove Letter To Equalize Frequency
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool equalFrequency(string word) 
    {
        if(word.length()<=1)
            return true;

        map<char,int> m;
        for(int i=0; i<word.length(); i++)
        {
            m[word[i]]++;
        }

        if(m.size() == 1)
            return true;

        map<int,int> count;

        vector<int> v;
        for(auto i:m)
            count[i.second]++;

        if(count.size()>2)
            return false;

        for(auto i:count)
            v.push_back(i.first);

        if(v.size() == 1)
        {
            if(v[0] == 1)
                return true;
            else
                return false;
        }
        else
        {
            if((v[0]==1 && count[v[0]] == 1) || (v[1]==1 && count[v[1]] == 1))
                return true;

            if(abs(v[0] - v[1]) != 1)
                return false;

            if(count[max(v[0],v[1])] == 1)
                return true;
        } 

        return false;
    }
};