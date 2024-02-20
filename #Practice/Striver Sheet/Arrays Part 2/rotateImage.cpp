// 48
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int row = matrix.size();
        int col = row;

        int ra = 0;
        int rb = row-1;
        int ca = 0;
        int cb = col-1;

        while(ra<rb)
        {
            for(int j=ca; j<cb; j++)
            {
                int reserve = matrix[ra][ca];

                for(int i=ra+1; i<=rb; i++)
                {
                    matrix[i-1][ca] = matrix[i][ca]; 
                }

                for(int i=ca+1; i<=cb; i++)
                {
                    matrix[rb][i-1] = matrix[rb][i];
                }

                for(int i=rb-1; i>=ra; i--)
                {
                    matrix[i+1][cb] = matrix[i][cb];
                }

                for(int i=cb-1; i>ca; i--)
                {
                    matrix[ra][i+1] = matrix[ra][i];
                }

                matrix[ra][ca+1] = reserve;
            }

            ra++;
            ca++;
            rb--;
            cb--;
        }
    }
};