#include <bits/stdc++.h>
using namespace std;
int partition(int arr[], int s, int e)
{
    int p = arr[s];
    int count = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] <= p)
            count++;
    }

    int pivot = s+count;
    swap(arr[s],arr[pivot]);

    int i=s;
    int j=e;
    while(i<pivot && j>pivot)
    {
        while(arr[j] > p)
            j--;

        while(arr[i] < p)
            i--;
        if(i<pivot && j>pivot)
            swap(arr[i++],arr[j--]);
    }

    return(pivot);
}
void QuickSort(int arr[], int s, int e)
{
    if(s>=e)
        return;

    int p = partition(arr,s,e);

    QuickSort(arr,s,p-1);
    QuickSort(arr,p+1,e);
}
int main()
{
    int arr[20];
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    cout << "Enter elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cin >> arr[i];
    }

    QuickSort(arr,0,n-1);

    cout << "Array elements: " << endl;
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
