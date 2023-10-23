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
            if(arr[mid-1] != ele)
            {
                cout << "First Index: " << mid << endl;
                f = 1;
                break;
            }
            else
            {
                e = mid-1;
            }
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


    s = 0;
    e = n-1;
    while(s<=e) //Need to check at s=e also
    {
        cout << "s: " << s << " e: " << e << endl;
        int mid = s + (e-s)/2;
        if(arr[mid] == ele)
        {
            if(arr[mid+1] != ele)
            {
                cout << "Last Index: " << mid << endl;
                break;
            }
            else
            {
                s = mid+1;
            }
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

    return 0;
}