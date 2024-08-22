// 994. Rotting Oranges
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int a, int b, int n, vector<vector<int>>& grid, vector<vector<bool>> &visited, int m)
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
        int m = grid.size();
        int n = grid[0].size();
        int countFresh = 0;
        queue<pair<int,int>> q;
        vector<vector<bool>> visited(m,vector<bool>(n,false));

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(grid[i][j] == 1)
                {
                    countFresh++;
                }
                else if(grid[i][j] == 2)
                {
                    q.push(make_pair(i,j));
                    visited[i][j] = 1;
                }
            }
        }
        int ans = 0;

        q.push(make_pair(-1,-1)); //after all rotten have been popped and after all fresh from these rotten have been made rotten, then only +1.
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

                if(check(a,b-1,m,grid,visited,n))
                {
                    countFresh--;
                    q.push(make_pair(a,b-1));
                    visited[a][b-1] = true;
                }

                if(check(a+1,b,m,grid,visited,n))
                {
                    countFresh--;
                    q.push(make_pair(a+1,b));
                    visited[a+1][b] = true;
                }

                if(check(a,b+1,m,grid,visited,n))
                {
                    countFresh--;
                    q.push(make_pair(a,b+1));
                    visited[a][b+1] = true;
                }

                if(check(a-1,b,m,grid,visited,n))
                {
                    countFresh--;
                    q.push(make_pair(a-1,b));
                    visited[a-1][b] = true;
                }
            }
        }

        if(countFresh > 0)
            return -1;

        return ans;
    }
};