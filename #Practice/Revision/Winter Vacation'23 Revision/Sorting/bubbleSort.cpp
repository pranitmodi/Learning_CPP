#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,6,2,6,1,3,2,7,3};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i++)
    {
        for(int j=0; j<(n-i); j++)
        {
            if(arr[j] > arr[j+1])
                swap(arr[j],arr[j+1]);
        }
    }

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}