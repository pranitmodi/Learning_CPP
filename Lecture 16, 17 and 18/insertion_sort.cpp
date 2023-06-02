#include <bits/stdc++.h>
using namespace std;
void insertionSort(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j = i-1;
        int temp = arr[i];
        while(j>=0)
        {
            if(arr[j] > temp) //as we do  arr[j+1] = arr[j]; thus temp is no longer equal to arr[is]
                arr[j+1] = arr[j];
            else
                break;
            j--;
        }
        arr[j+1] = temp;
    }
}
int main()
{
    int arr[20];
    int size;
    cout << "Enter the size: " << endl;
    cin >> size;

    cout << "Enter the array elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    insertionSort(arr, size);

    cout << "Sorted Array: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}