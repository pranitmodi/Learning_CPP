#include <bits/stdc++.h>
using namespace std;
bool searchMatrix(vector<vector<int>>& matrix, int target) 
{
    int row = matrix.size();
    int col = matrix[0].size();

    cout << "row: " << row << endl;
    cout << "col: " << col << endl;

    int s = 0;
    int e = row-1;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(matrix[mid][0] == target)
            return true;
        else if(matrix[mid][0] > target)
            e = mid - 1;
        else
            s = mid + 1;
    }    

    int z = s - 1;
    if(z < 0)
        z = 0;

    s = 0;
    e = col-1;

    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(matrix[z][mid] == target)
            return true;
        else if(matrix[z][mid] > target)
            e = mid-1;
        else
            s = mid+1;
    }

    return false;
}
int main()
{
    // vector<vector<int>> matrix = {  {1,3,5,7},
    //                                 {10,11,16,20},
    //                                 {23,30,34,60}};
    vector<vector<int>> matrix = {{1},{3}};
    cout << searchMatrix(matrix,3) << endl;
}