#include <iostream>
#include <stdio.h>
#include <limits.h>
using namespace std;
int getMax(int arr[], int size)
{
    int maxi = INT_MIN;
    for(int i=0; i<size; i++)
    {
        // if(arr[i] > max)
        //     max = arr[i];
        maxi = max(maxi, arr[i]); // Same
    }
    return maxi;
}
int getMin(int arr[], int size)
{
    int min = INT_MAX;
    for(int i=0; i<size; i++)
    {
        if(arr[i] < min)
            min = arr[i];
    }
    return min;
}
int main()
{
    int size;
    cout << "Enter the size of the array: " << endl;
    cin >> size;

    int arr[100];
    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << endl << "Max Element: " << getMax(arr, size) << endl << "Min Element: " << getMin(arr, size) << endl;
    return 0;
}