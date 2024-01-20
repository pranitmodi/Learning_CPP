#include <bits/stdc++.h>
using namespace std;
bool check(int x, int y, int n, vector<vector<int>> visited, vector<vector<int>> m)
{
    if((x < n && x >= 0) && (y<n && y>=0) && !visited[x][y] &&  m[x][y])
        return true;
    return false;
}
void solve(vector<string> &ans, int n, int x, int y, string s, vector<vector<int>> &visited, vector<vector<int>> m)
{
    if(x == n-1 && y == n-1)
    {
        ans.push_back(s);
        return;
    }
    
    visited[x][y] = 1;
    
    // down
    int newx = x+1;
    int newy = y;
    if(check(newx,newy,n,visited,m))
    {
        s.push_back('D');
        solve(ans,n,newx,newy,s,visited,m);
        s.pop_back();
    }
    
    // left
    newx = x;
    newy = y-1;
    if(check(newx,newy,n,visited,m))
    {
        s.push_back('L');
        solve(ans,n,newx,newy,s,visited,m);
        s.pop_back();
    }
    
    // right
    newx = x;
    newy = y+1;
    if(check(newx,newy,n,visited,m))
    {
        s.push_back('R');
        solve(ans,n,newx,newy,s,visited,m);
        s.pop_back();
    }
    
    // up
    newx = x-1;
    newy = y;
    if(check(newx,newy,n,visited,m))
    {
        s.push_back('U');
        solve(ans,n,newx,newy,s,visited,m);
        s.pop_back();
    }
    
    visited[x][y] = 0;
}
vector<string> findPath(vector<vector<int>> &m, int n) 
{
    vector<vector<int>> visited = m;
    for(int i=0; i<m.size(); i++)
    {
        for(int j=0; j<m.size(); j++)
        {
            visited[i][j] = 0;
        }
    }
    
    vector<string> ans;
    string s = "";
    int x = 0;
    int y = 0;
    if(m[x][y]) // if 0,0 itself is = 0
        solve(ans,m.size(),x,y,s,visited,m);
    else
        ans.push_back("-1");

    return ans;
}
