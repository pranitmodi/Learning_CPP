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

    int i,j;

    // int d = (size-1)/2;
    // for(i=0,j=size-1; i<=d; i++,j--)
    // {
    //     int temp = arr[i];
    //     arr[i] = arr[j];
    //     arr[j] = temp;
    // }

    for(i=0,j=size-1; i<=j; i++,j--) //Better Way -> loop till i<=j
    {
        swap(arr[i],arr[j]); // In Built Function
    }

    cout << "Reversed Array elements are: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}