#include <bits/stdc++.h>
using namespace std;
void insertionSort1(int arr[], int n)
{

}
void insertionSort2(int arr[], int n)
{

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

    insertionSort1(arr, n);

    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}