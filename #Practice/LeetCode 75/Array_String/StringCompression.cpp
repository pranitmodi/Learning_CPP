#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int compress(vector<char>& chars) 
    {
        if(chars.size() <= 1)
            return chars.size();

        int c = 1;
        char ch = chars[0];
        int h = 0;

        for(int i=1; i<chars.size(); i++)
        {
            while(chars[i] == ch)
            {
                c++;
                i++;
                if(i >= chars.size())
                    break;
            }

            if(c > 1)
            {
                chars[h++] = ch;
                string num = to_string(c);
                for(int i=0; i<num.length(); i++)
                {
                    chars[h++] = num[i];
                }
            }
            else
            {
                chars[h++] = ch;
            }
            
            if(i >= chars.size())
                break;

            c = 1;
            ch = chars[i];
        }    

        if(c == 1)
            chars[h++] = ch;

        return h;
    }
};