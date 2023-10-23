#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10];
    cout << "Enter elements:" << endl;
    for(int i=0; i<10; i++)
    {
        cin >> arr[i];
    }

    // cout << sizeof(arr) << " " << sizeof(int) << endl;
    cout << "Size of the array: " << sizeof(arr) << endl;
    cout << "Number of elements in the array: " << sizeof(arr)/sizeof(int) << endl;

    cout << "The elements are: ";
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}