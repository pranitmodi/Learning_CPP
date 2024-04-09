//168. Excel Sheet Column Title
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string convertToTitle(int columnNumber) 
    {
        string ans = "";
        while(columnNumber)
        {
            columnNumber--;
            char c = 'A' + (columnNumber % 26);
            ans = c + ans;
            columnNumber /= 26;
        }    
        return ans;
    }
};