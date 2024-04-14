#include<bits/stdc++.h>
using namespace std;
void permutation(int i, string s, vector<string> &ans)
{
    if(i == s.length())
    {
        ans.push_back(s);
        return;
    }

    for(int j=i; j<s.length(); j++)
    {
        swap(s[i],s[j]);
        permutation(i+1,s,ans);
        swap(s[i],s[j]);
    }
}
int main()
{
    string s = "abc";
    vector<string> ans;
    
    permutation(0,s,ans);


    for(auto i:ans)
    {
        cout << i << endl;
    }
}