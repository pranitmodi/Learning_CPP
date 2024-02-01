#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans, string str, int i)
{
    if(i>=str.length())
    {
        ans.push_back(str);
        return;
    }

    for(int j=i; j<str.length(); j++)
    {
        swap(str[i],str[j]);
        solve(ans,str,i+1);

        swap(str[i],str[j]);
    }
}
int main()
{
    string str;
    cout << "Enter: ";
    cin >> str;

    vector<string> ans;
    solve(ans,str,0);

    for(int i=0; i<ans.size(); i++)
    {
        cout << ans[i] << endl;
    }
}