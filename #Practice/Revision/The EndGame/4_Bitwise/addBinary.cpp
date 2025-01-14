// 67. Add Binary
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addBinary(string a, string b) 
    {
        if(b.length() > a.length())
            return addBinary(b,a);

        string ans = "";
        int counter = 0;
        int j = b.length()-1;
        for(int i=a.length()-1; i>=0; i--)
        {
            char a1 = a[i];
            char b1 = '0';
            if(j>=0)
                b1 = b[j--];

            if(a1 == '1' && b1 == '1')
            {
                if(counter == 0)
                    ans = '0' + ans;
                else
                    ans = '1' + ans;
                counter = 1;
            }
            else if(a1 == '1' || b1 == '1')
            {
                if(counter == 0)
                    ans = '1' + ans;
                else
                    ans = '0' + ans;
            }
            else
            {
                if(counter == 1)
                    ans = '1' + ans;
                else 
                    ans = '0' + ans;
                counter = 0;
            }
        }
        if(counter)
            ans = '1' + ans;

        return ans;
    }
};