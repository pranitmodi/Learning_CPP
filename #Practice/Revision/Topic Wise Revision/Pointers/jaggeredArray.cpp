// A jagged array, also known as a ragged array or irregular array is an array of arrays of which the member arrays can be of different lengths, producing rows of jagged edges when visualized as output.
#include <bits/stdc++.h>
using namespace std;
int main()
{
    cout << "Enter number of rows: " << endl;
    int row;
    cin >> row;

    vector<int> v;

    int **arr = new int *[row];
    for(int i=0; i<row; i++)
    {
        cout << "Enter number of elements for " << i+1 << "th row: ";
        int m;
        cin >> m;

        v.push_back(m);
        arr[i] = new int[m];
    }

    cout << "Enter elements: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<v[i]; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "The matrix: " << endl;
    for(int i=0; i<row; i++)
    {
        for(int j=0; j<v[i]; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    for(int i=0; i<row; i++)
    {
        delete [] arr[i];
    }

    delete []arr;

}