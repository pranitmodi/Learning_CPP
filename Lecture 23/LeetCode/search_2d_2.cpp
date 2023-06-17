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

    int s = 0;
    int e = col-1;
    while(s < e)
    {
        int mid = s + ((e-s)/2);
        int midVal = matrix[0][mid];
        if(midVal == target)
            found = 1;
        else if(midVal > target)
            e = mid-1;
        else
            s = mid+1;
    }
    int c = s;

    s = 0;
    e = row-1;
    while(s < e)
    {
        int mid = s + Math.ceil((double)((e-s)/2));
        int midVal = matrix[mid][0];
        cout << "in" << " mid:" << mid << endl;
        if(midVal == target)
            found = 1;
        else if(midVal > target)
            e = mid-1;
        else
            s = mid+1;
        cout << "in" << " e:" << e << endl;
        cout << "in" << " s:" << s << endl;
    }
    int r = s;

    cout << r << " , " << c << endl;

    for(int i=0; i<=r; i++)
    {
        if(matrix[i][c] == target)
            found = 1;
    }

    for(int i=0; i<=c; i++)
    {
        if(matrix[r][i] == target)
            found = 1;
    }

    if(found)
        cout << "Found!" << endl;
    else
        cout << "Not Found." << endl;


    return 0;
}