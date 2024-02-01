// 240
#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    int s = 0;
    int e = col-1;

    while(s<=row-1 && e>=0)
    {
        if(matrix[s][e] == target)
            return true;
        else if(target > matrix[s][e])
        {
            s++;
        }
        else
            e--;
    } 

    return false;
}