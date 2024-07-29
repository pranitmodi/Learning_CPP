#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,1,1,1,0,0,0,0,1,2,1,1,2,0,0,1,0,2,1,0,2};
    int n = sizeof(arr)/sizeof(int);

    int i = 0;
    int k = 0;
    int j = n-1;

    while(k < j)
    {
        switch(arr[k])
        {
            case 0:
                swap(arr[i],arr[k]);
                i++;
                k++;
                break;

            case 1:
                k++;
                break;

            case 2:
                swap(arr[k],arr[j]);
                j--;
                break;
        }
    }

    cout << "Sorted Array: ";
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}