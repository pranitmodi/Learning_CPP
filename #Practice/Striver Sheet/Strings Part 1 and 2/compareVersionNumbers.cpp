// 165
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compareVersion(string version1, string version2) 
    {
        int i = 0;
        int j = 0;

        while(i<version1.length() && j<version2.length())
        {
            string s1 = "";
            while(i<version1.length() && version1[i] != '.')
                s1 += version1[i++];

            i++;

            string s2 = "";
            while(j<version2.length() && version2[j] != '.')
                s2 += version2[j++];

            j++;

            if(s1 == "" && s2 == "")
                continue;

            int t1 = stoi(s1);
            int t2 = stoi(s2);

            if(t1>t2)
                return 1;
            else if(t1<t2)
                return -1;
        }    

        if(i<version1.length() && j >= version2.length())
        {
            while(i<version1.length())
            {
                if(version1[i] == '0' || version1[i] == '.')
                    i++;
                else
                    break;
            }
            if(i<version1.length())
                return 1;
        }

        if(j<version2.length() && i >= version1.length())
        {
            while(j<version2.length())
            {
                if(version2[j] == '0' || version2[j] == '.')
                    j++;
                else
                    break;
            }
            if(j<version2.length())
                return -1;
        }

        return 0;
    }
};