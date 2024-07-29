#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[10] = {0}; // initializing all as 0, by default garbage values are there.
    fill_n(arr,5,2); // first 5 as 2 and rest as 0.

    cout << "Elements of the array: " << endl;
    for(int i=0; i<10; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl; 

    cout << "Size of the array: " << sizeof(arr)/sizeof(int) << endl;
}