#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,6,2,6,1,3,2,7,3};
    int n = sizeof(arr)/sizeof(int);

    for(int i=0; i<n; i++)
    {
        int p = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[p])
                p = j;
        }
        swap(arr[i],arr[p]);
    }

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}