#include <bits/stdc++.h>
using namespace std;
//For input of the array elements and the size
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
//For printing the array elements
void printArray(int a[], int size)
{
    cout << "Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << a[i] <<" ";
    }
    cout << endl;
}
// Binary Search Code
int binarySearch(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = (start + end)/2;

    while(start <= end)
    {
        if(arr[mid] == key)
            return mid;
        else if(arr[mid] > key)
            end = mid -1;
        else
            start = mid + 1;
        
        mid = (start + end)/2;
    }
    return -1;
}
int main()
{
    int arr[20];
    int size = inputArray(arr);
    printArray(arr, size);

    int key;
    cout << "Enter the element to be found: " << endl;
    cin >> key;

    int pos = binarySearch(arr, size, key);
    cout << "The position of " << key << " is: " << pos << endl;

    return 0;
}