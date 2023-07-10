#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter the number of digits: ";
    cin >> n;

    int arr[20];
    cout << "Enter elements:" << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    int i=0,j=n-1; 
    int mid = 0;
    while(mid<j)
    {
        if(arr[mid] == 0)
        {
            swap(arr[i],arr[mid]);
            i++;
            mid++;
        }
        if(arr[mid] == 1)
        {
            mid++;
        }
        if(arr[mid] == 2)
        {
            swap(arr[mid],arr[j]);
            j--;
        }
    }

    cout << "Sorted elements:" << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}