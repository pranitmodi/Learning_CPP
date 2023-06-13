#include <bits/stdc++.h>
using namespace std;
bool check(int arr[], int n)
{
    int c=0;
    for(int i=1; i<n; i++)
    {
        if(arr[i-1] > arr[i])
            c++;
    }
    if(arr[n-1] > arr[0])
        c++;
    
    if(c <= 1)
        return true;
    else
        return false;
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[20];

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    cout << "Result: " << check(arr,n);
    
    return 0;
}