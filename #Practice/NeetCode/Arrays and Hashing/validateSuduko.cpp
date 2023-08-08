#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) 
    {
        map<char,bool> check;
        for(int i = 0; i<9; i++)
        {
            char ch = (char) i + 49;
            check[ch] = false;
        }

        cout << " r okay" << endl;

        // all rows
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char ch = board[i][j];
                if(ch != '.')
                {
                    if(check[ch] == true)
                        return false;
                    check[ch] = true;
                }
            }

            for(int i = 0; i<9; i++)
            {
                char ch = (char) i + 49;
                check[ch] = false;
            }
        }

        cout << " b okay" << endl;

        // all columns
        for(int i=0; i<9; i++)
        {
            for(int j=0; j<9; j++)
            {
                char ch = board[j][i];
                if(ch != '.')
                {
                    if(check[ch] == true)
                        return false;
                    check[ch] = true;
                }
            }

            for(int i = 0; i<9; i++)
            {
                char ch = (char) i + 49;
                check[ch] = false;
            }
        }

        cout << "okay" << endl;

        // all boxes
        for(int k=0; k<9; k=k+3)
        {
            for(int i=k; i<k+3; i++)
            {
                for(int j=0; j<3; j++)
                {
                    char ch = board[i][j];
                    if(ch != '.')
                    {
                        if(check[ch] == true)
                            return false;
                        check[ch] = true;
                    }
                }
            }
            
            for(int i = 0; i<9; i++)
            {
                char ch = (char) i + 49;
                check[ch] = false;
            }

            for(int i=k; i<k+3; i++)
            {
                for(int j=3; j<6; j++)
                {
                    char ch = board[i][j];
                    if(ch != '.')
                    {
                        if(check[ch] == true)
                            return false;
                        check[ch] = true;
                    }
                }
            }

            for(int i = 0; i<9; i++)
            {
                char ch = (char) i + 49;
                check[ch] = false;
            }

            for(int i=k; i<k+3; i++)
            {
                for(int j=6; j<9; j++)
                {
                    char ch = board[i][j];
                    if(ch != '.')
                    {
                        if(check[ch] == true)
                            return false;
                        check[ch] = true;
                    }
                }
            }

            for(int i = 0; i<9; i++)
            {
                char ch = (char) i + 49;
                check[ch] = false;
            }
        }
        return true;
    }
};