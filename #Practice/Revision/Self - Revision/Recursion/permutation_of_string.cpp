#include <bits/stdc++.h>
using namespace std;
void permutation(string s, int i, vector<string> &ans)
{
    if(i >= s.length())
    {
        ans.push_back(s);
        return;
    }

    for(int j=i; j<s.length(); i++)
    {
        swap(s[i],s[j]);
        permutation(s,i+1,ans);
        swap(s[i],s[j]);
    }
}