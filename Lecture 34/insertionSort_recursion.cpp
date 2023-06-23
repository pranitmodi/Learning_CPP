#include <bits/stdc++.h>
using namespace std;
void insertionSort1(int arr[], int n)
{
    
}
void insertionSort2(int arr[], int n)
{
    for(int i=1; i<n; i++)
    {
        int j = i;
        while(j>0)
        {
            if(arr[j] < arr[j-1])
                swap(arr[j], arr[j-1]); //traditionally they shift each and in the last put arr[i] to its place, but i am swapping so same logic
            else
                break;
            j--;
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

    insertionSort2(arr, n);

    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}