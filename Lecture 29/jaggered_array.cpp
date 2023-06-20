// A jagged array, also known as a ragged array or irregular array is an array of arrays of which the member arrays can be of different lengths, producing rows of jagged edges when visualized as output.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int row;
    cout << "Enter the number of rows: ";
    cin >> row;

    vector <int>v;

    int **arr = new int*[row];
    for(int i=0; i<row; i++)
    {
        int m;
        cout << "Enter row length: " << endl;
        cin >> m;
        arr[i] = new int[m];
        v.push_back(m);
    }

    cout << "Enter elements: " << endl;
    for(int i=0; i<row; i++)
    {
        int col = v[i];
        for(int j=0; j<col; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Final Array: " << endl;
    for(int i=0; i<row; i++)
    {
        int col = v[i];
        for(int j=0; j<col; j++)
        {
            cout << arr[i][j] << "\t";
        }
        cout << endl;
    }

    return 0;
}