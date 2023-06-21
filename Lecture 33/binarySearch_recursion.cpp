#include <bits/stdc++.h>
using namespace std;
bool binarySearch(int arr[], int size, int key)
{
    int s = 0;
    int e = size-1;

    if(s > e)
        return 0;   

    int mid = s + (e-s)/2;
    if(arr[mid] == key)        
        return true;
    else if(arr[mid] > key)
        e = mid-1;
    else 
        s = mid+1;

    return(binarySearch(arr+s,e+1,key));

}
int main()
{
    int arr[20];
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Enter the key element: ";
    int key;
    cin >> key;

    bool ans = binarySearch(arr,n,key); 
    if(ans)
        cout << "Found!" << endl;
    else
        cout << "Not Found." << endl;
        
    return 0;
}