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

    cout << "Array: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<col; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int a,b,q;
    a=0;
    b=col-1;
    q=row-1;

    int c = 0;
    int total = col*row;
    while(c<total)
    {
        for(int i=a;i<=b && c<total;i++)
        {
            cout << arr[a][i] << " ";
            c++;
        }
        a++;
        b--;

        for(int i=a;i<=q && c<total;i++)
        {
            cout << arr[i][b+1] << " ";
            c++;
        }
        q--;
        
        for(int i=b;i>=a && c<total;i--)
        {
            cout << arr[q+1][i] << " ";
            c++;
        }

        for(int i=q+1; i>=a && c<total; i--)
        {
            cout << arr[i][a-1] << " ";
            c++;
        }
    }
    cout << endl;

    return 0;
}


// if(q == 0)
// {
//     for(int i=a;i<=b;i++)
//     {
//         spiral.push_back(matrix[0][i]);
//     }
//     return spiral;
// }
// if(b == 0)
// {
//     for(int i=a;i<=q;i++)
//     {
//         spiral.push_back(matrix[i][0]);
//     }
//     return spiral;
// }