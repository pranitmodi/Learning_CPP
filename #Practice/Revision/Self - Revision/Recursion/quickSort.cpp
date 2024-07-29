#include <bits/stdc++.h>
using namespace std;
int partition(int s, int e, int arr[])
{
    int ele = arr[s];
    int c = 0;
    for(int i=s+1; i<=e; i++)
    {
        if(arr[i] < ele)
            c++;
    }

    swap(arr[s],arr[s+c]);
    int i = s;
    int j = e;
    while(i<(s+c) && j>(s+c))
    {
        while(arr[i] < ele)
            i++;
        
        while(arr[j] > ele)
            j--;

        if(i<(s+c) && j>(s+c))
            swap(arr[i++],arr[j--]);
    }

    return s+c;
}
void quickSort(int s, int e, int arr[])
{
    if(s >= e)
        return;

    int p = partition(s,e,arr);
    quickSort(s,p-1,arr);
    quickSort(p+1,e,arr);
}