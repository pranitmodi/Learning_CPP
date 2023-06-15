#include <bits/stdc++.h>
using namespace std;
bool checkEqual(int ch[], int ch1[])
{
    for(int i=0; i<26; i++)
    {
        if(ch[i]!=ch1[i])
            return false;
    }
    return true;
}
bool permutation_in_string(string s1, string s2)
{
    int ch[26] = {0};
    for(int i=0; i<s1.size(); i++)
    {
        int index = s1[i] - 'a';
        ch[index]++;
    }

    // Alternate Method
    // for(int i=0; i<=(s2.size()-s1.size()); i++)
    // {
    //     string str = s2.substr(i,s1.size());
    //     int ch1[26] = {0};
    //     // cout << str << endl;
    //     for(int j=0; j<str.size(); j++)
    //     {
    //         int index = str[j] - 'a';
    //         ch1[index]++;
    //     }
    //     if(checkEqual(ch, ch1))
    //     {
    //         return true;
    //     }
    // }

    string str = s2.substr(0,s1.size());
    int ch1[26] = {0};
    cout << str << endl;
    for(int j=0; j<str.size(); j++)
    {
        int index = str[j] - 'a';
        ch1[index]++;
    }
    if(checkEqual(ch, ch1))
    {
        return true;
    }

    for(int i=1; i<=(s2.size()-s1.size()); i++)
    {
        str = s2.substr(i,s1.size());
        cout << str << endl;
        int index = s2[i-1] - 'a';
        ch1[index]--;
        int ele = i + s1.size() - 1;
        index = s2[ele] - 'a';
        ch1[index]++;
        if(checkEqual(ch, ch1))
        {
            return true;
        }
    }

    return false;
}
int main()
{
    string s1,s2;
    cout << "Enter the first string: ";
    cin >> s1;
    cout << "Enter the second string: ";
    cin >> s2;

    cout << permutation_in_string(s1,s2) << endl;

    return 0;
}