// 463. Island Perimeter
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    int check(int r, int c, vector<vector<int>>& grid)
    {
        if(r<grid.size() && r>=0 && c<grid[0].size() && c>=0)
        {
            if(grid[r][c] == 1)
                return 0;
            else
                return 1;
        }
        else
            return 1;
    }
    int islandPerimeter(vector<vector<int>>& grid) 
    {
        int ans = 0;
        for(int i=0; i<grid.size(); i++)
        {
            for(int j=0; j<grid[0].size(); j++)
            {
                if(grid[i][j] == 1)
                {
                    ans += check(i,j-1,grid);
                    ans += check(i,j+1,grid);
                    ans += check(i+1,j,grid);
                    ans += check(i-1,j,grid);
                }
            }
        }
        return ans;
    }
};