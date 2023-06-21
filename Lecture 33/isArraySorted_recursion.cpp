#include <bits/stdc++.h>
using namespace std;
bool isSorted(int arr[], int size)
{
    if(size == 1 || size == 0)
        return true;

    if(arr[size-1] > arr[size-2])
        return(isSorted(arr, size-1));
    else
        return false;
}
int main()
{
    int arr1[] = {1,2,3,4,5,6};
    int arr2[] = {1,4,5,2,3,5};

    cout << isSorted(arr1,6) << endl;
    cout << isSorted(arr2,6) << endl;

    return 0;
}