#include <bits/stdc++.h>
using namespace std;
void merge(int s, int e, vector<int> &arr)
{
    int mid = s + (e-s)/2;
    int l1 = mid - s + 1;
    int l2 = e - mid;

    int *arr1 = new int[l1];
    int *arr2 = new int[l2];

    int counter = s;
    for(int i=0; i<l1; i++)
    {
        arr1[i] = arr[counter++];
    }
    for(int i=0; i<l2; i++)
    {
        arr2[i] = arr[counter++];
    }

    int i = 0;
    int j = 0;
    int counter = s;
    while(i<l1 && j<l2)
    {
        if(arr1[i] <= arr2[j])
        {
            arr[counter++] = arr1[i++];
        }
        else
        {
            arr[counter++] = arr2[j++];
        }
    }
    while(i<l1)
    {
        arr[counter++] = arr1[i++];
    }
    while(j<l2)
    {
        arr[counter++] = arr2[j++];
    }

    delete []arr1;
    delete []arr2;
}
void mergeSort(int s, int e, vector<int> &arr)
{
    if(s >= e)
        return;
    
    int mid = s + (e-s)/2;

    mergeSort(s,mid,arr);
    mergeSort(mid+1,e,arr);

    merge(s,e,arr);
}