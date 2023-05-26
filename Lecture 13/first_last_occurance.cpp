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
int firstOccurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            end = mid-1;//To focus on the left part
        }
        else if(arr[mid] > key)
            end = mid -1;
        else
            start = mid + 1;

        mid = start + (end-start)/2;
    }
    return ans;
}
int lastOccurance(int arr[], int size, int key)
{
    int start = 0;
    int end = size-1;
    int mid = start + (end-start)/2;
    int ans = -1;

    while(start <= end)
    {
        if(arr[mid] == key)
        {
            ans = mid;
            start = mid + 1;//To focus on the right part
        }
        else if(arr[mid] > key)
            end = mid -1;
        else
            start = mid + 1;

        mid = start + (end-start)/2;
    }
    return ans;
}
int main()
{
    int arr[20];
    int size = inputArray(arr);
    printArray(arr, size);

    int key;
    cout << "Enter the element to be found: " << endl;
    cin >> key;

    int first = firstOccurance(arr, size, key);
    int last = lastOccurance(arr, size, key);

    cout << "First Occurance: " << first << endl << "Last Occurance: " << last << endl;

    return 0;
}