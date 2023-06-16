#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr1[3][4];
    int arr2[3][4];

    cout << "Enter for row wise array: " << endl;
    // Row wise input
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> arr1[i][j];
        }
    }

    cout << "Enter for column wise array: " << endl;
    //Column wise input
    for(int i=0; i<4; i++)
    {
        for(int j=0; j<3; j++)
        {
            cin >> arr2[j][i];
        }
    }

    // Row wise printing
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << arr1[i][j] << " ";
        }
        cout << endl;
    }

    //Column wise printing = same as row wise printing
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }






    return 0;
}