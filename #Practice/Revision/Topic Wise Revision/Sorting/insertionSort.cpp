#include <bits/stdc++.h>
using namespace std;
int main()
{
    int arr[] = {2,3,6,2,6,1,3,2,7,3};
    int n = sizeof(arr)/sizeof(int);

    for(int i=1; i<n; i++)
    {
        // we will place this card/element to its currect place in the sorted subarray in this iteration
        int key = arr[i];

        // comparing starts from one left to its left, if its bigger just shift that eleemnt to the right
        // keep shifting until no longer greater than key element
        int j=i-1;
        
        while(j>=0 && arr[j]>key)
        {
            arr[j+1] = arr[j];
            j--;
        }

        // then just place the ket element to that jth element
        arr[j+1] = key;
    }

    cout << "Sorted Array: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}