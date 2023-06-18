// LeetCode
// 74. Search a 2D Matrix
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of column: ";
    cin >> col;

    int matrix[row][col];

    cout << "Enter elements for array: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> matrix[i][j];
        }
    }

    cout << "Array: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    int found = 0;
    int target;
    cout << "Send target: ";
    cin >> target;

    if( row == 1 && col == 1)
    {
        if(matrix[0][0] == target)
        {
            cout << true << endl;
            return 0;
        }
    } 

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
        {
            cout << true << endl;
            return 0;
        }
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

    s=0;
    e=col-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        int midVal = matrix[r][mid];
        if(midVal == target)
        {
            cout << true << endl;
            return 0;
        }
        else if(midVal > target)
        {
            e = mid - 1;
        }
        else
        {
            s = mid + 1;
        }
    }
    cout << false << endl;

    return 0;
}