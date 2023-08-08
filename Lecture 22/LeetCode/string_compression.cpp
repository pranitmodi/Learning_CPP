// LeetCode - 443
#include <bits/stdc++.h>
using namespace std;
int main()
{
    vector<char> chars;
    string str;
    cout << "Enter String :";
    cin >> str;

    for(int i=0; i<str.length(); i++)
    {
        chars.push_back(str[i]);
    }

    // A better optimized solution in NOTES

    int l = chars.size();
    string s = "";
    for(int i=0; i<l;)
    {
        char ch = chars[i];
        if(i == l-1) //if only last character left or string has only one character
        {
            s.push_back(ch);
            break;
        }
        int count = 1;
        if(chars[i+1] == ch)
        {
            i++;
            while(chars[i] == ch)
            {
                count++;
                i++;
                if(i == l) //is already reached the last character
                    break;
            }
            s.push_back(ch);
            if(count <= 9)
                s.append(to_string(count));
            else
            {
                s.append(to_string(count/10));
                s.append(to_string(count%10));
            }
        }
        else
        {
            s.push_back(ch);
            i++;
        }
    }
    int l1 = s.length();
    for(int i=0; i<l1; i++)
    {
        chars[i] = s[i];
    }

    cout << "Final: " << s << endl;
 
    return l1;
    return 0;
}