#include <bits/stdc++.h>
using namespace std;
void solve(vector<vector<int>> &arr, int n, int x, int y, string path, vector<vector<int>> visited,vector<string> &ans)
{
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    visited[x][y] = 1;

    // right
    int newx = x;
    int newy = y+1;
    if((newx<n && newy<n && newx>=0 && newy >=0) && !visited[newx][newy] && arr[newx][newy])
    {
        path.push_back('R');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    // down
    newx = x+1;
    newy = y;
    if((newx<n && newy<n && newx>=0 && newy >=0) && !visited[newx][newy] && arr[newx][newy])
    {
        path.push_back('D');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    // up
    newx = x-1;
    newy = y;
    if((newx<n && newy<n && newx>=0 && newy >=0) && !visited[newx][newy] && arr[newx][newy])
    {
        path.push_back('U');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    // left
    newx = x;
    newy = y-1;
    if((newx<n && newy<n && newx>=0 && newy >=0) && !visited[newx][newy] && arr[newx][newy])
    {
        path.push_back('L');
        solve(arr,n,newx,newy,path,visited,ans);
        path.pop_back();
    }

    visited[x][y] = 0;
}
vector < string > searchMaze(vector < vector < int >> & arr, int n) 
{
    vector<vector<int>> visited;
    vector<string> ans;
    string path;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = 0;
        }
    }
    solve(arr,n,0,0,path,visited,ans);
}