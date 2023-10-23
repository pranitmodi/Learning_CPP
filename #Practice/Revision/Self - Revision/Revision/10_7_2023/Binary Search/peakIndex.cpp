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

    // Better Approach woulf have been to check for conditions which would not satisfy peak element and if not true, then the changes
    // if(arr[mid+1] > arr[mid])
    //     start = mid + 1;
    // else if(arr[mid-1] > arr[mid])
    //     end = mid - 1;
    // else 
    //     return mid;

    int s=0;
    int e=n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid+1] < arr[mid])
            e = mid - 1;
        else
            s = mid + 1;
    }
    cout << "Peak element: " << arr[s] << endl;

    return 0;
}