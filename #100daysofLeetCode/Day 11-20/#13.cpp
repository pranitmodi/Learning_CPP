// 289. Game of Life
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool check(int m, int n, int x, int y)
    {
        if(x<m && x>=0 && y>=0 && y<n)
            return true;
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) 
    {
        int m = board.size();
        int n = board[0].size();

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                // 1 to 0 => 2
                // 0 to 1 => 3
                int live = 0;
                int dead = 0;
                for(int k=-1; k<=1; k++)
                {
                    if(check(m,n,i+k,j-1))
                    {
                        if(board[i+k][j-1] == 1 || board[i+k][j-1] == 2)
                            live++;
                        else
                            dead++;
                    }
                }

                for(int k=-1; k<=1; k++)
                {
                    if(check(m,n,i+k,j+1))
                    {
                        if(board[i+k][j+1] == 1 || board[i+k][j+1] == 2)
                            live++;
                        else
                            dead++;
                    }
                }

                if(check(m,n,i+1,j))
                {
                    if(board[i+1][j] == 1 || board[i+1][j] == 2)
                        live++;
                    else
                        dead++;
                }

                if(check(m,n,i-1,j))
                {
                    if(board[i-1][j] == 1 || board[i-1][j] == 2)
                        live++;
                    else
                        dead++;
                }

                if(board[i][j] == 1 || board[i][j] == 2)
                {
                    if(live<2)
                        board[i][j] = 2;
                    else if(live > 3)
                        board[i][j] = 2;
                }
                else
                {
                    if(live == 3)
                        board[i][j] = 3;
                }
            }
        }

        for(int i=0; i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(board[i][j] == 3)
                    board[i][j] = 1;
                else if(board[i][j] == 2)
                    board[i][j] = 0;
            }
        }
    }
};