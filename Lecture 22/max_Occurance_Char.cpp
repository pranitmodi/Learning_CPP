#include <bits/stdc++.h>
using namespace std;
int main()
{
    string s;
    cout << "Enter String: ";
    getline(cin,s);

    int l = s.length();
    int ch[26] = {0};

    for(int i=0; i<l; i++)
    {
        int r;
        if(s[i]>='a' && s[i]<='z')
        {
            r = s[i] - 'a';
        }
        else if(s[i]>='A' && s[i]<='Z')
        {
            r = s[i] - 'A';
        }
        ch[r]++;
    }

    int m = ch[0];
    int f = 0;
    for(int i=1; i<25; i++)
    {
        if(ch[i] > m)
            f = i;
    }


    cout << "Max Occurance Character: " << (char)(f + 'A') << endl;
    return 0;
}