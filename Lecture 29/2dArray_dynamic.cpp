#include <bits/stdc++.h>
using namespace std;
int main()
{   
    int n;
    cout << "Enter the size of array:";
    cin >> n;

    int **arr = new int*[n]; //each element of this array should have a pointer
    for(int i=0; i<n; i++)
    {
        arr[i] = new int[n]; //assigning individual aaray to each of these pointer elements
    }

    //INPUT
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cin >> arr[i][j];
        }
    }

    //PRINTING
    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<n; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    // deleting/releasing the memory space
    for(int i=0; i<n; i++)
    {
        delete [] arr[i];
    }

    delete [] arr;

    return 0;
}