#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &ans, int n, string s)
{
    if(n == 0)
    {
        ans.push_back(s);
        return;
    }

    solve(ans,n-1,s+"0");
    solve(ans,n-1,s+"1");
}
int main()
{
    int n = 3;
    vector<string> ans;
    solve(ans,n,"");
    for(auto i:ans)
        cout << i << endl;
}