#include <bits/stdc++.h>
using namespace std;
bool isPresent(int arr[], int size, int key)
{
   if(size == 0)
        return false;
    
    if(arr[0] == key)
        return true;
    else
        return(isPresent(arr+1,size-1,key));
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

    bool ans = isPresent(arr,n,key); 
    if(ans)
        cout << "Found!" << endl;
    else
        cout << "Not Found." << endl;
        
    return 0;
}