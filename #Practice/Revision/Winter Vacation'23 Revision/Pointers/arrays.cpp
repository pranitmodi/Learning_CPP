#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {1,2,23,4,5,6,7};
    int *p = arr;
    cout << "arr: " << arr << endl;
    cout << "*arr: " << *arr << endl;
    cout << "&arr: " << &arr << endl;

    cout << "Printing the array: " << endl;
    for(int i=0; i<7; i++)
    {
        // arr[i] = *(arr+i)
        cout << *(arr+i) << " ";
    }
    cout << endl;
}