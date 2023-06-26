#include <bits/stdc++.h>
using namespace std;
bool isSafe(int x, int y,int n,vector<vector<int>> m, vector<vector<int>> visited)
{
    if((x>=0 && x<n) && (y>=0 && y<n) && visited[x][y]==0 && m[x][y]==1)
        return true;
    return false;
}
void RatUncle(vector<vector<int>> m, vector<vector<int>> visited, int n, int x, int y, string path, vector<string>& ans)
{
    // base condition ie reached
    if(x == n-1 && y == n-1)
    {
        ans.push_back(path);
        return;
    }

    // since here, so marked visited
    visited[x][y] = 1;

    //down
    int newx = x+1;
    int newy = y;
    if(isSafe(newx,newy,n,m,visited))
    {
        path.push_back('D');
        RatUncle(m,visited,n,newx,newy,path,ans);

        // after returning and in order to check for other alternate paths, we POP
        // ALTERNATE PATHS FROM THE CURRENT X AND Y COORDINATES
        path.pop_back();
    }

    //up
    newx = x-1;
    newy = y;
    if(isSafe(newx,newy,n,m,visited))
    {
        path.push_back('U');
        RatUncle(m,visited,n,newx,newy,path,ans);
        path.pop_back();
    }

    //left
    newx = x;
    newy = y-1;
    if(isSafe(newx,newy,n,m,visited))
    {
        path.push_back('L');
        RatUncle(m,visited,n,newx,newy,path,ans);
        path.pop_back();
    }

    //right
    newx = x;
    newy = y+1;
    if(isSafe(newx,newy,n,m,visited))
    {
        path.push_back('R');
        RatUncle(m,visited,n,newx,newy,path,ans);
        path.pop_back();
    }

    // if all the search for the alternate path from the current x and y exhausted, now going to the previous coordinate and thus visited as 0.
    // becaus maybe in some other way it will reach the same x,y.
    visited[x][y] = 0;
}
int main()
{
    vector<vector<int>> m;
    int n;
    cout << "Enter n: ";
    cin >> n;

    // input the matrix
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        vector <int> t;
        for(int j=0; j<n; j++)
        {
            int w;
            cin >> w;
            t.push_back(w);
        }
        m.push_back(t);
    }

    vector<vector<int>> visited = m;
    vector<string> ans;

    // initialising the visited matrix
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            visited[i][j] = 0;
        }
    }

    // src coordinated and path
    int src_x = 0;
    int src_y = 0;
    string path = "";

    RatUncle(m,visited,n,src_x,src_y,path,ans);

    // to give the answer in sorted order
    sort(ans.begin(),ans.end());

    // printing the answer
    for(int i=0; i<ans.size(); i++)
    {
        for(int j=0; j<ans[i].length(); j++)
        {
            cout << ans[i][j];
        }
        cout << " ";
    }

    return 0;
}