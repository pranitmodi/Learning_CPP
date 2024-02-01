#include <bits/stdc++.h>
using namespace std;
void merge(int arr[], int s, int e)
{
    int mid = s + (e-s)/2;
    int l1 = mid-s+1;
    int l2 = e-mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int c = s; // this has to be s not 0.
    for(int i=0; i<l1; i++) // always start i with 0
    {
        arr1[i] = arr[c++];
    }

    for(int i=0; i<l2; i++) // always start i with 0
    {
        arr2[i] = arr[c++];
    }

    int i = 0;
    int j = 0;
    c = s; // this has to be s not 0.

    while(i<l1 && j<l2)
    {
        if(arr1[i] <= arr2[j])
            arr[c++] = arr1[i++];
        else    
            arr[c++] = arr2[j++];
    }
    while(j<l2)
    {
        arr[c++] = arr2[j++];
    }
    while(i<l1)
    {
        arr[c++] = arr1[i++];
    }

    // delete afterwards
    delete []arr1;
    delete []arr2;
}
void mergeSort(int arr[], int s, int e)
{
    cout << arr[s] << " " << arr[e] << endl;
    if(s >= e)
        return;

    int mid = s + (e-s)/2;
    mergeSort(arr,s,mid);
    mergeSort(arr,mid+1,e);

    merge(arr,s,e);
}
int main()
{
    int arr[] = {2,5,8,2,1,45,7,84,2,14,7,2,0,733};
    int n = sizeof(arr)/sizeof(int);
    cout << "Size: " << n << endl;

    mergeSort(arr,0,n-1); 

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}