#include <bits/stdc++.h>
using namespace std;
void printSum(int arr[], int size)
{
    int sum = 0;
    for(int i=0; i<size; i++)
    {
        sum = sum + arr[i];
    }

    cout << "Sum of the Array is: " << sum;
}
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
    printSum(arr, size);

    return 0;
}