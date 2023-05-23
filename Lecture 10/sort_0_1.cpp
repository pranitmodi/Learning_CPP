#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[20];
    int size;
    cout << "Enter the number of elements: " << endl;
    cin >> size;

    cout << "Enter elements: " << endl;
    for(int i=0; i<size; i++)
    {
        cin >> arr[i];
    }

    int i=0;
    int j=size-1;
    while(i<j)
    {
        if(arr[i] == 0)
            i++;
        if(arr[j] == 1)
            j--;
        if((arr[i] == 1) && (arr[j] == 0))
        {
            arr[i] = 0;
            arr[j] = 1;
            i++;
            j--;
        }
    }

    cout << "Sorted array: " << endl;
    for(int i=0; i<size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}