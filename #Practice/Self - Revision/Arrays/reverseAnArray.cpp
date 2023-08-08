#include <bits/stdc++.h>
using namespace std;
void reverse(int *arr, int n)
{
    int i=0;
    int j=n-1;
    while(i<j)
    {
        swap(arr[i++],arr[j--]);
    }
}
void printArr(int *arr, int n)
{
    for(int i=0; i<n; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}
int main()
{
    int arr[10] = {1,2,3,4,5,6,7,8,9,10};
    reverse(arr,10);
    printArr(arr,10);
}