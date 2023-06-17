#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[3][4];

    cout << "Enter elements for array: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cin >> arr[i][j];
        }
    }

    cout << "Array: " << endl;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int largest = 0;
    int pos = 0;
    cout << "Row wise sum:" << endl;
    for(int i=0;i<3;i++)
    {
        int sum=0;
        for(int j=0;j<4;j++)
        {
            sum = sum + arr[i][j];
        }
        cout << "Sum of row " << i+1 << " is: " << sum << endl;
        if(sum > largest)
        {
            largest = sum;
            pos = i+1;
        }
    }
    cout << "Largest row sum is of row " << pos << endl;
    return 0;
}