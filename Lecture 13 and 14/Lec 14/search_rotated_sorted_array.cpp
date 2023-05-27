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

int findPivot(int arr[], int size)
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

int binarySearch(int arr[], int size, int s, int e, int key)
{
    int start = s;
    int end = e;
    int mid;
    while(start <= end)
    {
        mid = s + (e-s)/2;
        if(arr[mid] > key)
            end = mid - 1;
        else 
            start = mid + 1;

        if(arr[mid] == key)
            return mid;
    }
    return -1;
}

int main()
{
    int arr[20];
    int size = inputArray(arr);
    printArray(arr, size);

    int pivot_value = findPivot(arr, size);
    int key;
    cout << "Enter the key element: " << endl;
    cin >> key;

    int pos;
    if(key > arr[0])
        pos = binarySearch(arr, size, 0, pivot_value-1,key);
    else
        pos = binarySearch(arr, size, pivot_value, size-1,key);

    cout << "Position of Key: " << pos << endl; 
    return 0;
}