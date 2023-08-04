// leetCode - 125
#include <bits/stdc++.h>
using namespace std;
class Solution
{
    public:
        bool check(char ch)
        {
            if((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
                return true;
            return false;
        }
        void toLower(char &ch)
        {
            if(ch >= 'A' && ch <= 'Z')
                ch = (ch - 'A' + 'a');
        }
        bool isPalindrome(string s) 
        {
            int l = s.length();
            string w;
            for(int i=0; i<l; i++)
            {
                if(check(s[i]))
                {
                    toLower(s[i]);
                    w.push_back(s[i]);
                }
            }    

            int i = 0;
            int j = w.length() - 1;

            while(i <= j)
            {
                if(w[i] == w[j])
                {
                    i++;
                    j--;
                }
                else
                    return false;
            }
            return true;
        }
};