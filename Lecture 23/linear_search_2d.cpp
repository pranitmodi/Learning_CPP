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
    
    cout << "Enter target: ";
    int target;
    cin >> target;

    int c = 0;
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<4; j++)
        {
            if(arr[i][j] == target)
            {
                c = 1;
                break;
            }
        }
        if(c == 1)
            break;
    }
    if(c == 1)
    {
        cout << "Found!" << endl;
    }
    else    
        cout << "Not Found." << endl;

    return 0;
}