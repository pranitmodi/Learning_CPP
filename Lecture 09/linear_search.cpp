#include <bits/stdc++.h>
using namespace std;
bool linear_search(int arr[], int size, int key) //Code for Linear Search
{
    for(int i=0; i<size; i++)
    {
        if(key == arr[i])
            return true;
    }
    return false;
}
int main()
{
    //Entering the size
    int size;
    cout << "Enter the number of elements: " << endl;
    cin >> size;

    // Declaring the array
    int arr[10];

    // Taking array elements as input
    cout << "Enter the elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    // Printing Array Elements
    cout << "Array elements: ";
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    // Asking for the element to be searched for
    cout << "Enter the element to be searched for: " << endl;
    int ele;
    cin >> ele;

    // Checking for the element in the array
    if(linear_search(arr, size, ele))
        cout << "Element found!" << endl;
    else
        cout << "Element not found!" << endl;

    return 0;
}