// LeetCode
// 48. Rotate Image
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cout << "Enter number of rows: ";
    cin >> row;
    col = row; // n*n matrix

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

    // int row = matrix.size();
    // int col = row;

    int a = 0;
    int b = col-1;
    int q = 0;
    int p = row-1;

    int w = b;
    while(a<b) //to go till the innermost ring
    {
        for(int i=1; i<=w; i++) //for each ring, no of times the elements needed to be shifted
        {   
            int store = matrix[a][a]; //the first element

            //starting column
            for(int j=q+1; j<=p; j++)
            {
                swap(matrix[j][a],matrix[j-1][a]);
            }

            //ending row
            for(int j=a+1;j<=b;j++)
            {
                swap(matrix[p][j],matrix[p][j-1]);
            }

            //ending column
            for(int j=p-1; j>=q; j--)
            {
                swap(matrix[j][b],matrix[j+1][b]);
            }

            //starting row
            for(int j=b-1; j>=(a+1); j--)
            {
                swap(matrix[q][j],matrix[q][j+1]);
            }

            // putting this back
            matrix[q][a+1] = store;
        }
        a++;
        b--;
        q++;
        p--;
        w = w-2; //Number of steps decreases by 2
    }

    cout << "Rotated Array: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}