#include <bits/stdc++.h>
using namespace std;
void bubbleSort1(int arr[], int n)
{
    if(n == 0 || n == 1)
        return;

    for(int j=0; j<n-1; j++)
    {
        if(arr[j+1] < arr[j])
            swap(arr[j+1],arr[j]);
    }

    bubbleSort1(arr, n-1);
}
void bubbleSort2(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        for(int j=0; j<n-i; j++)
        {
            if(arr[j+1] < arr[j])
                swap(arr[j+1],arr[j]);
        }
    }
}
int main()
{
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    int arr[20];
    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    bubbleSort1(arr, n);

    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}