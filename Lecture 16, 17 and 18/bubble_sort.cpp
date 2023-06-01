#include <bits/stdc++.h>
using namespace std;
void bubbleSort(int arr[], int n)
{
    for(int i = 1; i<n; i++) // from 1 to n-1
    {
        bool swapping = false;
        for(int j = 0; j<n-i; j++) // because the last element in each iteration is automatically the largest
        {
            if(arr[j+1] < arr[j])
            {
                swap(arr[j+1], arr[j]);
                swapping = true;
            }
        }
        if(swapping == false) //because the array has been sortred, thus no swapping happended
            break;
    }
}
int main()
{
    int n;
    int arr[20];

    cout << "Enter the number of elements: " << endl;
    cin >> n;

    cout << "Enter the elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort(arr,n);

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}