#include <bits/stdc++.h>
using namespace std;
bool isArraySorted(int *arr, int size)
{
    if(size == 0 || size == 1)
        return true;
    
    if(arr[0] < arr[1])
        return isArraySorted(arr+1,size-1);
    else 
        return false;
}
int main()
{
    int arr1[] = {1,2,4,5,6,78};
    int arr2[] = {2,4,2,5,67};

    cout << isArraySorted(arr1,6) << endl << isArraySorted(arr2,5) << endl; 
}