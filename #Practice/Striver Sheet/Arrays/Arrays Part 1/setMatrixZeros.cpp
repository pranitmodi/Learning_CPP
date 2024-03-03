// 73
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>> v;
        for(int i=0; i<matrix.size(); i++)
        {
            for(int j=0; j<matrix[0].size(); j++)
            {
                if(matrix[i][j] == 0)
                {
                    v.push_back(make_pair(i,j));
                }
            }
        }

        for(int i=0; i<v.size(); i++)
        {
            int row = v[i].first;
            int col = v[i].second;

            for(int k=row; k>=0; k--)
            {
                matrix[k][col] = 0;
            }

            for(int k=row; k<matrix.size(); k++)
            {
                matrix[k][col] = 0;
            }

            for(int k=col; k>=0; k--)
            {
                matrix[row][k] = 0;
            }

            for(int k=col; k<matrix[0].size(); k++)
            {
                matrix[row][k] = 0;
            }
        }
    }
};