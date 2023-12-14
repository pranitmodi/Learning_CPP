// 1071
#include <bits/stdc++.h>
using namespace std;
// BETTER CODE
class Solution {
public:
    int gcd(int a,int b){
        if(b==0){
            return a;
        }
        return gcd(b,a%b);
    }
    string gcdOfStrings(string str1, string str2) {
        if(str1+str2 != str2+str1){
            return "";
        }
        int len1=str1.length();
        int len2=str2.length();
        int ans=gcd(len1,len2);
        return (str1.substr(0,ans));
        
    }
};


// MY CODE
class Solution {
public:
    bool check(string s1, string s2)
    {
        int c = 0;
        string w = "";
        for(int i=0; i<s2.length(); i++)
        {
            if(c >= s1.length())
            {    
                if(w != s1)
                    return false;

                w = "";
                c = 0;
            }   

            w = w + s2[i];
            c++;
        }
        if(w != s1)
            return false;
        return true;
    }
    string gcdOfStrings(string str1, string str2) 
    {
        if(str1 == str2)
            return str1;

        string s1,s2;
        if(str1.length() < str2.length())
        {
            s1 = str1;
            s2 = str2;
        }    
        else
        {
            s2 = str1;
            s1 = str2;
        }

        if(check(s1,s2))
            return s1;

        int l1 = s1.length()/2;
        while(l1 > 0)
        {
            string str = s1.substr(0,l1);
            cout << str << endl;
            if(check(str,s1) && check(str,s2))
                return str;

            l1--;
        }

        return "";
    }
};