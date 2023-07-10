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

    cout << "Enter the element to search for: ";
    int ele;
    cin >> ele;

    int f=0;
    int s = 0;
    int e = n-1;
    while(s<=e) //Need to check at s=e also
    {
        cout << "s: " << s << " e: " << e << endl;
        int mid = s + (e-s)/2;
        if(arr[mid] == ele)
        {
            f = 1;
            cout << "Found at index: " << mid << endl;
            break;
        }
        else if(arr[mid] > ele)
        {
            e = mid-1;
        }
        else
        {
            s = mid + 1;
        }
    }
    if(f == 0)
        cout << "Not Found!" << endl;

    return 0;
}