#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout << "Enter n: ";
    cin >> n;
    
    cout << "Enter elements: " << endl;
    int arr[20];
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }
    
    cout << "Enter the element to be found: ";
    int w;
    cin >> w;
    
    int left = 0;
    int right = n-1;
    
    while(left <= right)
    {
        int mid = left + (right-left)/2;
        if(arr[mid] == w)
        {
            cout << "Found! @ " << mid << endl;
            return 0;
        }
        else if(arr[mid] > w)
            right = mid - 1;
        else    
            left = mid + 1;
    }
    cout << "Not Found!" << endl;
}