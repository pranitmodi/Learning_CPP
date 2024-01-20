// 51
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void adjust(int n, vector<vector<string>> &ans, vector<vector<int>> board)
    {   
        vector<string> str;
        for(int i=0; i<n; i++)
        {
            string s;
            for(int j=0; j<n; j++)
            {
                if(board[i][j])
                    s.push_back('Q');
                else
                    s.push_back('.');
            }
            str.push_back(s);
        }
        ans.push_back(str);
    }
    bool isSafe(int n, int row, int col, vector<vector<int>> board)
    {
        // no need to check for column

        // checking for row (only the left part)
        int x = row;
        int y = col;

        while(y>=0)
        {
            if(board[x][y])
                return false;
            
            y--;
        }

        // checking for north-east diagonal
        x = row;
        y = col;
        while(x>=0 && y>=0)
        {
            if(board[x][y])
                return false;

            x--;
            y--;
        }

        // checking for south-east diagonal
        x = row;
        y = col;
        while(x<n && y>=0) // x<n - remember
        {
            if(board[x][y])
                return false;
            
            y--;
            x++;
        }

        return true;
    }
    void solve(vector<vector<string>> &ans, vector<vector<int>> board, int n, int col)
    {
        if(col == n)
        {
            adjust(n,ans,board);
            return;
        }

        // traversing all the rows for the coulmn
        for(int row=0; row<n; row++)
        {
            if(isSafe(n,row,col,board))
            {
                board[row][col] = 1;
                solve(ans,board,n,col+1);
                board[row][col] = 0;
            }
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<vector<int>> board(n, vector<int>(n,0));

        solve(ans,board,n,0);
        return ans;
    }
};