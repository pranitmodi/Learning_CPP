#include <bits/stdc++.h>
using namespace std;
void printArr(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    // int arr[10]; - Grabage Values
    // int arr[10] = {0}; - All Zeros
    // int arr[10] = {85}; - only the value of the first index is 85
    
    // int arr[10];
    // fill_n(arr,10,3); - all have 3 as value

    int arr[5];
    int size = sizeof(arr)/sizeof(int);
    cout << "Size of Array: " << size << endl;
    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }
    printArr(arr+2,size-2);
}