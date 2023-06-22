#include <bits/stdc++.h>
using namespace std;
void selectionSort1(int arr[], int n)
{
    if(n == 1 || n == 0)
        return;
    
    int pos = arr[0];
    for(int j=1; j<n; j++)
    {
        if(arr[j] < arr[pos])
            pos = j;
    }
    swap(arr[0],arr[pos]);

    selectionSort1(arr+1, n-1);
}
void selectionSort2(int arr[], int n)
{
    for(int i=0; i<n-1; i++)
    {
        int pos = i;
        for(int j=i+1; j<n; j++)
        {
            if(arr[j] < arr[pos])
                pos = j;
        }
        swap(arr[i],arr[pos]);
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

    selectionSort1(arr, n);

    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}