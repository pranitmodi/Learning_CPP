#include <bits/stdc++.h>
using namespace std;
void subSequence(string s, int i, string w, vector<string> &ans)
{
    if(i>=s.length())
    {
        ans.push_back(w);
        return;
    }

    subSequence(s,i+1,w,ans);
    w.push_back(s[i]);
    subSequence(s,i+1,w,ans);
}
int main()
{
    vector<string> ans;
    string w;
    string s = "abcdef";

    subSequence(s,0,w,ans);
    sort(ans.begin(),ans.end());

    for(int i = 0; i < ans.size(); i++)
    {
        cout << ans[i] << endl;
    }

}