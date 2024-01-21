// 37
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isSafe(int row, int col, vector<vector<char>>& board, int val)
    {
        char ch = (char)(48 + val);
        for(int i=0; i<board.size(); i++)
        {
            //checking for row
            if(board[row][i] == ch)
                return false;

            //checking for col
            if(board[i][col] == ch)
                return false;

            //for 3*3 matrix
            if(board[3*(row/3) + i/3][3*(col/3) + i%3] == ch)
                return false;
        }
        return true;
    }
    bool solve(vector<vector<char>>& board)
    {
        int n = board[0].size();

        for(int row=0; row<n; row++)
        {
            for(int col=0; col<n; col++)
            {
                if(board[row][col] == '.')
                {
                    for(int val=1; val<=9; val++)
                    {
                        if(isSafe(row,col,board,val))
                        {
                            board[row][col] = (char)(48 + val);
                            bool further = solve(board);
                            if(further)
                                return true;
                            else
                                board[row][col] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& board) {
        bool b = solve(board);
    }
};