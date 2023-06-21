#include <bits/stdc++.h>
using namespace std;
int SumArray(int arr[], int size)
{
    if(size == 0)
        return 0;

    int ele = arr[size-1];
    return(ele + SumArray(arr,size-1));
}
int main()
{
    int arr1[] = {1,2,3};
    int arr2[] = {1,4,5};

    cout << "Sum: " << SumArray(arr1,3) << endl;
    cout << "Sum: " << SumArray(arr2,3) << endl;

    return 0;
}