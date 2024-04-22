// 12. Integer to Roman
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    string intToRoman(int num) 
    {
        string ans = "";
        while(num > 0)
        {
            if(num >= 1000)
            {
                int r = num/1000;
                num = num%1000;
                while(r >= 1)
                {
                    ans.push_back('M');
                    r--;
                }
            }
            else if(num >= 500)
            {
                if(num >= 900)
                {
                    ans += "CM";
                    num = num%900;
                }
                else
                {
                    num = num%500;
                    ans += "D";
                }
            }
            else if(num >= 100)
            {
                if(num>=400)
                {
                    ans += "CD";
                    num = num%400;
                }
                else
                {
                    int r = num/100;
                    num = num%100;
                    while(r>=1)
                    {
                        ans.push_back('C');
                        r--;
                    }
                }
            }
            else if(num >= 50)
            {
                if(num >= 90)
                {
                    ans += "XC";
                    num = num%90;
                }
                else
                {
                    num = num%50;
                    ans += "L";
                }
            }
            else if(num >= 10)
            {
                if(num >= 40)
                {
                    ans += "XL";
                    num = num%40;
                }
                else
                {
                    int r = num/10;
                    num = num%10;
                    while(r>=1)
                    {
                        ans.push_back('X');
                        r--;
                    }
                }
            }
            else if(num >= 5)
            {
                if(num == 9)
                {
                    ans += "IX";
                }
                else
                {
                    int i = 5;
                    ans += "V";
                    while(i<num)
                    {
                        ans += "I";
                        i++;
                    }
                }
                num = 0;
            }
            else
            {
                if(num == 4)
                {
                    ans += "IV";
                }
                else
                {
                    int i = 1;
                    while(i<=num)
                    {
                        ans += "I";
                        i++;
                    }
                }
                num = 0;
            }
        }
        return ans;
    }
};