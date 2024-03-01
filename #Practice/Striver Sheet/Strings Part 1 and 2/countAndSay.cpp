// 38
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string countAndSay(int n) 
    {
        if(n == 1)
            return "1";

        string str = countAndSay(n-1);
        string ans = "";
        for(int i=0; i<str.length(); i++)
        {
            int c = 1;
            while(i<str.length()-1 && str[i] == str[i+1])
            {
                c++;
                i++;
            }
      
            ans += to_string(c);
            ans.push_back(str[i]);
        }
        return ans;
    }
};