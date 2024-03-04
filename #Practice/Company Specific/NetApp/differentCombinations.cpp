#include <bits/stdc++.h>
using namespace std;
void solve(vector<string> &s, int n, string str)
{
    if(n == 0)
    {
        s.push_back(str);
        return;
    }

    solve(s,n-1,str+"0");
    solve(s,n-1,str+"1");
}
int main()
{
    vector<string> s;
    int n = 3;
    solve(s,n,"");
    for(auto i:s)
        cout << i << endl;
}