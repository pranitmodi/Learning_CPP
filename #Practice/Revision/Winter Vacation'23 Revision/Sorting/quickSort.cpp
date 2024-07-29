#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e)
{
    int ele = arr[s];

    int c = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= ele)
            c++;
    }

    int p = s + c;
    swap(arr[s],arr[p]); // forgot to swap

    int i = s; // has to be s not 0
    int j = e;

    while(i<p && j>p)
    {
        while(arr[i] < ele)
            i++;

        while(arr[j] > ele)
            j--;

        if(i<p && j>p)
        {
            swap(arr[i++],arr[j--]);
        }
    }

    return p;
}
void quickSort(int arr[], int s, int e)
{
    if(s >= e)
        return;

    int p = partition(arr,s,e);

    quickSort(arr,s,p-1); // forgot -1
    quickSort(arr,p+1,e);
}
int main()
{
    int arr[] = {2,5,8,2,1,45,7,84,2,14,7,2,0,733};
    int n = sizeof(arr)/sizeof(int);
    cout << "Size: " << n << endl;

    quickSort(arr,0,n-1); 

    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    } 
    cout << endl;

    return 0;
}