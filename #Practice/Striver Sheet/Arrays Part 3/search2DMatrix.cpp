// 74
#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) 
    {
        int s = 0;
        int e = matrix.size()-1;

        while(s<e)
        {
            int mid = s + (e-s)/2;
            if(matrix[mid][0] == target)
                return true;
            else if(matrix[mid][0] > target)
                e = mid - 1;
            else
            {
                if(matrix[mid+1][0] > target)
                {
                    s = mid;
                    break;
                }
                else
                    s = mid + 1;
            }
        }    

        int w = s;
        s = 0;
        e = matrix[0].size()-1;

        while(s<=e)
        {
            int mid = s + (e-s)/2;
            if(matrix[w][mid] == target)
                return true;
            else if(matrix[w][mid] > target)
                e = mid - 1;
            else
                s = mid + 1;
        }

        return false;
    }
};