// 415. Add Strings
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string addStrings(string num1, string num2) 
    {
        if(num2.length() > num1.length())
            return addStrings(num2,num1);

        int l = num1.length() - num2.length();

        for(int i=1; i<=l; i++)
            num2 = '0' + num2;

        int c = 0;
        string ans = "";

        for(int i=num2.length()-1; i>=0; i--)
        {
            int a = (((int)num2[i])-48) + (((int)num1[i])-48);
            if(c == 1)
            {
                a = a + 1;
                c = 0;
            }

            if(a>9)
                c = 1;
            
            ans = to_string(a%10) + ans;
        }

        if(c == 1)
            ans = to_string(1) + ans;

        return ans;
    }
};