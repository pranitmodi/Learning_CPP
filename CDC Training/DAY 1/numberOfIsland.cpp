// 200
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int i, int j, vector<vector<char>>& grid)
    {
        if((i>=0 && i<grid.size()) && (j>=0 && j<grid[0].size()) && grid[i][j] == '1')
            return true;
        return false;
    }
    void dfs(int i, int j, vector<vector<char>>& grid, vector<vector<int>>& visited)
    {
        visited[i][j] = 1;
        int l[4] = {0,0,1,-1};
        int r[4] = {-1,1,0,0};

        for(int w=0; w<4; w++)
        {
            int row = i+l[w];
            int col = j+r[w];

            if(check(row,col,grid) && visited[row][col] == 0)
                dfs(row,col,grid,visited);
        }

    }
    int numIslands(vector<vector<char>>& grid) {
        vector<vector<int>> visited(grid.size(),vector<int>(grid[0].size(),0));
        int count = 0;

        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(!visited[i][j] && grid[i][j] == '1')
                {
                    dfs(i,j,grid,visited);
                    count++;
                }
            }
        }

        return count;
    }
};