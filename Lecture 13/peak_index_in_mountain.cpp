// LeetCode
// 852. Peak Index in a Mountain Array
// Using Binary Search
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
int peakOccurance(int arr[], int size)
{
    int start = 0;
    int end = size-1;
    int mid;

    while(start <= end)
    {
        mid = start + (end-start)/2;
        if(arr[mid+1] > arr[mid])
        {
            start = mid + 1;
        }
        else if(arr[mid-1] > arr[mid])
        {
            end = mid - 1;
        }
        else
            return mid;
    }
}
int main()
{
    int arr[20];
    int size = inputArray(arr);
    printArray(arr, size);

    int peak = peakOccurance(arr, size);

    cout << "Peak Occurance at Index: " << peak << endl;

    return 0;
}
