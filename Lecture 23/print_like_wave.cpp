#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row,col;
    cout << "Enter number of rows: ";
    cin >> row;
    cout << "Enter number of column: ";
    cin >> col;

    int arr[row][col];

    cout << "Enter elements for array: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cin >> arr[i][j];
        }
    }
    
    cout << "Printing in curve: " << endl;
    for(int i=0;i<col;i++)           
    {
        if(i%2 == 0)
        {
            for(int j=0;j<row;j++)
            {
                cout << arr[j][i] << " ";
            }
        }
        else
        {
            for(int j=row-1;j>=0;j--)
            {
                cout << arr[j][i] << " ";
            }
        }
        cout << endl;
    }

    return 0;
}