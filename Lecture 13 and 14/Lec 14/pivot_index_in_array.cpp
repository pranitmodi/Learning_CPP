#include <bits/stdc++.h>
using namespace std;

int inputArray(int a[])
{
    cout << "Enter the number of elements: " << endl;
    int size;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> a[i];
    }
    return size;
}

void printArray(int a[], int size)
{
    cout << "Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}

int pivot(int arr[], int size)
{
    int start = 0;
    int end = size - 1;
    while(start < end)
    {
        int mid = start + (end-start)/2;
        if(arr[mid] >= arr[0])
            start = mid + 1;
        else if(arr[mid] < arr[0])
            end = mid;
        
        if(arr[mid-1] > arr[mid])
            return mid;
    }
    return -1;
}

int main()
{
    int arr[20];
    int size = inputArray(arr);
    printArray(arr, size);

    int pivot_value = pivot(arr, size);
    cout << "Pivot Value: " << pivot_value << endl; 
    return 0;
}