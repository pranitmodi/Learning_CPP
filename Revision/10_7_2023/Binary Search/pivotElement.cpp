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

    int s = 0;
    int e = n-1;
    while(s<=e)
    {
        int mid = s + (e-s)/2;
        if(arr[mid-1] > arr[mid])
        {
            cout << mid << " : " << arr[mid] << endl;
            break;
        }
        else if(arr[mid] > arr[0])
        {
            s = mid + 1;
        }
        else
        {
            e = mid - 1;
        }
    }


    return 0;
}