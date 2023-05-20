#include <bits/stdc++.h>
using namespace std;
int takeInput(int arr[])
{
    cout << "Enter the number of elements: " << endl;
    int size;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    cout << "Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return size;
}
int main()
{
    int arr[20];
    int size = takeInput(arr);
    int m;
    if(size % 2 ==0)
        m = size-2;
    else
        m = size-3;
    
    for(int i=0; i<=m; i=i+2)
    {
        swap(arr[i],arr[i+1]);
    }

    cout << "Alternate Swapped Array: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}