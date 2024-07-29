// 994. Rotting Oranges
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int a, int b, int n, vector<vector<int>>& grid, vector<vector<int>> &visited, int m)
    {
        if(a<n && a>=0 && b>=0 && b<m && grid[a][b] && !visited[a][b])
        {
            visited[a][b] = 1;
            return true;
        }
        return false;
    }
    int orangesRotting(vector<vector<int>>& grid) 
    {
        queue<pair<int,int>> q;
        int normal = 0;
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> visited(n,vector<int>(m,0));

        for(int i=0; i<n; i++)
        {
            for(int j=0; j<m; j++)
            {
                if(grid[i][j] == 1)
                    normal++;
                else if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                    visited[i][j] = 1;
                }
            }
        }    
        if(normal == 0)
            return 0;
        else if(q.empty())
            return -1;

        int ans = 0;
        
        q.push(make_pair(-1,-1));
        while(!q.empty())
        {
            pair<int,int> p = q.front();
            q.pop();

            if(p.first == -1)
            {
                if(q.empty())
                    break;

                ans++;
                q.push(make_pair(-1,-1));
            }
            else
            {
                int a = p.first;
                int b = p.second;

                if(check(a+1,b,n,grid,visited,m))
                {
                    normal--;
                    grid[a+1][b] = 2;
                    q.push(make_pair(a+1,b));
                }

                if(check(a-1,b,n,grid,visited,m))
                {
                    normal--;
                    grid[a-1][b] = 2;
                    q.push(make_pair(a-1,b));
                }

                if(check(a,b+1,n,grid,visited,m))
                {
                    normal--;
                    grid[a][b+1] = 2;
                    q.push(make_pair(a,b+1));
                }

                if(check(a,b-1,n,grid,visited,m))
                {
                    normal--;
                    grid[a][b-1] = 2;
                    q.push(make_pair(a,b-1));
                }
            }
        }

        if(normal > 0)
            return -1;
        return ans;
    }
};