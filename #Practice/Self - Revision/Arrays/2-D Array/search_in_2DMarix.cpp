// LeetCode - 74
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int row = matrix.size();
        int col = matrix[0].size();

        if( row == 1 && col == 1)
        {
            if(matrix[0][0] == target)
                return true;
        } 

        // finding out the row 
        int s = 0;
        int e = row-1;
        while(s<e)
        {
            int mid = s + (e-s)/2;
            int midVal = matrix[mid][0];
            if(matrix[mid][0]<target && matrix[mid+1][0]>target)
            {
                s = mid;
                break;
            }
            if(midVal == target)
                return true;
            else if(midVal > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        int r = s;
        cout << "r:" << r << endl;

        // now checking in the row, where the element could exist
        s=0;
        e=col-1;
        while(s<=e)
        {
            int mid = s + (e-s)/2;
            int midVal = matrix[r][mid];
            if(midVal == target)
                return true;
            else if(midVal > target)
            {
                e = mid - 1;
            }
            else
            {
                s = mid + 1;
            }
        }
        return false;
    }
};