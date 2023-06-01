#include <bits/stdc++.h>
using namespace std;
void selectionSort(int arr[], int n)
{
    for(int i = 0; i<n-1; i++)
    {
        int pos = i;
        for(int j = i+1; j<n; j++)
        {
            if(arr[j] < arr[pos])
            {
                pos = j;
            }
        }
        swap(arr[pos], arr[i]);
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

    selectionSort(arr,n);

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}